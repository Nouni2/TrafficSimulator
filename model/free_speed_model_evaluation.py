import numpy as np
import matplotlib.pyplot as plt
from scipy.integrate import cumulative_trapezoid
import pandas as pd
from scipy.spatial import cKDTree

# Paramètres pour la distribution de Pareto inversée
alpha = 1.4
tolerance = 1  # Tolérance en pourcentage
v_max = 100  # Vitesse maximale (km/h)
N = 5000  # Nombre de véhicules
k = 0.55  # Valeur de k entre 0 et 1
ratio = 0.8  # Ratio cible

# Lecture des valeurs de beta depuis le fichier CSV
df_beta = pd.read_csv('data/beta_values.csv')

# Fonction pour trouver la valeur la plus proche dans le DataFrame
def find_nearest(df, v_max, ratio):
    tree = cKDTree(df[['v_max', 'r']])
    dist, idx = tree.query([[v_max, ratio]])
    return df.iloc[idx[0]]['beta']

# Trouver la valeur de beta correspondant à v_max et ratio
beta = find_nearest(df_beta, v_max, ratio)

# Calcul de la tolérance en km/h
v_tol = v_max * (tolerance / 100)

# Calcul de v_param en utilisant la formule avec correction
v_param = v_max * (1.05 + 0.03 * k) - (beta * alpha / (alpha + 1)) ** (1 / alpha)

# Domaine de v en km/h
v = np.linspace(0.1, v_param, 10000)

# Calcul de la densité de probabilité non normalisée
epsilon = 1e-10  # Petite valeur pour éviter les divisions par zéro
g_v = (alpha * beta**alpha) / (v_param - v + epsilon)**(alpha + 1) * np.exp(-beta * (v_param - v + epsilon)**(-alpha))

# Assurer que les valeurs infinies ou indéfinies sont éliminées
g_v = np.nan_to_num(g_v, nan=0.0, posinf=0.0, neginf=0.0)

# Normalisation de g_v en divisant par sa valeur maximale
g_v_normalized = g_v / np.max(g_v)

# Calcul de la fonction de répartition cumulative F(v)
F_v = cumulative_trapezoid(g_v_normalized, v, initial=0)

# Normalisation de F(v)
F_v_normalized = F_v / np.max(F_v)

# Sélection des vitesses pour N véhicules
v_selected = np.interp(np.random.uniform(0, 1, N), F_v_normalized, v)

# Calcul du ratio des véhicules dont les vitesses dépassent v_max + v_tol
ratio_exceeding = np.sum(v_selected > (v_max + v_tol)) / N

# Tracé du nuage de points des vitesses
plt.figure(figsize=(14, 8))
plt.scatter(v_selected, np.random.uniform(0, 1, N), alpha=0.5, s=10, color='blue', label='Véhicules')
plt.axvline(x=v_max, color='green', linestyle='--', label='$v_{max}$')
plt.axvline(x=v_max + v_tol, color='red', linestyle='--', label='$v_{max} + v_{tol}$')
plt.xlabel('Vitesse (km/h)')
plt.ylabel('Nombre de véhicules')
plt.title('Distribution des Vitesses des Véhicules')
plt.legend()
plt.show()

print(f"Ratio des véhicules dépassant {v_max + v_tol} km/h : {ratio_exceeding:.2%}")
