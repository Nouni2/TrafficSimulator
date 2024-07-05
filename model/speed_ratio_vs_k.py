import numpy as np
import matplotlib.pyplot as plt
from scipy.integrate import cumulative_trapezoid

# Paramètres pour la distribution de Pareto inversée
alpha = 1.1
v_max = 100  # Vitesse maximale (km/h) fixe
v_tol = 5  # Tolérance (km/h)
N = 1000  # Nombre de véhicules
k = np.linspace(0, 1, 1000)  # Différentes valeurs de k entre 0 et 1

# Domaine de beta
beta_values = [0.2, 0.4, 0.6, 0.8,1, 2]

# Transformation linéaire pour k
def k_transform(k):
    return 0.05 + 0.03 * k_nouveau

for beta in beta_values:
    ratios = []
    for k_nouveau in k:
        # Calcul de k_ancien
        k_a= k_transform(k_nouveau)

        # Calcul de v_param en utilisant la formule avec correction
        v_param = v_max * (1 + k_a) - (beta * alpha / (alpha + 1)) ** (1 / alpha)

        # Domaine de v en km/h
        v = np.linspace(0.1, v_param, 10000)  # Évite les valeurs de v proches de v_param

        # Calcul de la densité de probabilité non normalisée
        g_v = (alpha * beta**alpha) / (v_param - v)**(alpha + 1) * np.exp(-beta * (v_param - v)**(-alpha))

        # Assurer que les valeurs infinies ou indéfinies sont éliminées
        g_v = np.nan_to_num(g_v, nan=0.0, posinf=0.0, neginf=0.0)

        # Normalisation de g_v en divisant par sa valeur maximale
        g_v_normalized = g_v / np.max(g_v)

        # Calcul de la fonction de répartition cumulative F(v)
        F_v = cumulative_trapezoid(g_v_normalized, v, initial=0)

        # Normalisation de F_v
        F_v_normalized = F_v / np.max(F_v)

        # Sélection des vitesses pour N véhicules
        v_selected = np.interp(np.random.uniform(0, 1, N), F_v_normalized, v)

        # Calcul du ratio des véhicules dont les vitesses dépassent v_max + v_tol
        ratio_exceeding = np.sum(v_selected > (v_max + v_tol)) / N
        ratios.append(ratio_exceeding)

    # Tracé du ratio en fonction de k_nouveau pour une valeur de beta
    plt.plot(k * 100, ratios, linestyle='-', label=f'Beta = {beta}')

plt.xlabel('k (%)')
plt.ylabel('Ratio des véhicules dépassant $v_{max} + v_{tol}$')
plt.title('Ratio des véhicules dépassant $v_{max} + v_{tol}$ en fonction de k pour différentes valeurs de Beta')
plt.legend()
plt.grid(True)
plt.show()
