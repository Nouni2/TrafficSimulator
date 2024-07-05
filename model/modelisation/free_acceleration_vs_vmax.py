import numpy as np
import matplotlib.pyplot as plt
from scipy.integrate import cumulative_trapezoid
import pandas as pd
from scipy.spatial import cKDTree

# Paramètres pour la distribution de Pareto inversée
alpha = 1.4
tolerance = 1  # Tolérance en pourcentage
N = 10000  # Nombre de véhicules
k = 0.55  # Valeur de k entre 0 et 1
ratio = 0.8  # Ratio cible

# Paramètres pour la distribution gaussienne de t_acc_per_unit_v
t0 = 0.15
v_ref = 16.26

# Lecture des valeurs de beta depuis le fichier CSV
df_beta = pd.read_csv('data/beta_values.csv')

# Fonction pour trouver la valeur la plus proche dans le DataFrame
def find_nearest(df, v_max, ratio):
    tree = cKDTree(df[['v_max', 'r']])
    dist, idx = tree.query([[v_max, ratio]])
    return df.iloc[idx[0]]['beta']

# Fonction pour t_acc_per_unit_v
def t_acc_per_unit_v(v, t0, v_ref):
    return t0 * (1 + np.sqrt(v / v_ref))

# Plage de valeurs pour v_max
v_max_values = np.linspace(0, 240, 10)  # de 50 km/h à 200 km/h

a_moyennes = []

for v_max in v_max_values:
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

    # Tirage aléatoire des temps d'accélération par unité de vitesse
    t_acc_per_unit_v_samples = np.random.normal(t0, t0 * 0.1, N)  # 10% écart type pour la distribution

    # Calcul des accélérations pour atteindre les vitesses cibles
    a_selected = v_selected / (t_acc_per_unit_v(v_selected, t0, v_ref) * v_selected)

    # Calcul de l'accélération moyenne
    a_moyenne = np.mean(a_selected)
    a_moyennes.append(a_moyenne)

# Tracé de l'accélération moyenne en fonction de v_max
plt.figure(figsize=(14, 8))
plt.plot(v_max_values, a_moyennes, marker='o', linestyle='-', color='blue', label='Accélération moyenne')
plt.xlabel('Vitesse maximale (km/h)')
plt.ylabel('Accélération moyenne (m/s²)')
plt.title('Accélération moyenne en fonction de la vitesse maximale')
plt.legend()
plt.grid(True)
plt.show()
