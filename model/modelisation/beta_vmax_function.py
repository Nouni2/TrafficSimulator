import numpy as np
import matplotlib.pyplot as plt
from scipy.integrate import cumulative_trapezoid
from scipy.optimize import minimize_scalar

# Fonction pour calculer le ratio des véhicules dans l'intervalle de tolérance
def compute_ratio(beta, alpha, v_max, v_interval, N, r, k):
    v_tol = v_interval / 100 * v_max
    v_param = v_max * (1.05 + 0.03 * k) - (beta * alpha / (alpha + 1)) ** (1 / alpha)
    v = np.linspace(0.1, v_param, 10000)
    g_v = (alpha * beta**alpha) / (v_param - v)**(alpha + 1) * np.exp(-beta * (v_param - v)**(-alpha))
    g_v = np.nan_to_num(g_v, nan=0.0, posinf=0.0, neginf=0.0)
    g_v_normalized = g_v / np.max(g_v)
    F_v = cumulative_trapezoid(g_v_normalized, v, initial=0)
    F_v_normalized = F_v / np.max(F_v)
    v_selected = np.interp(np.random.uniform(0, 1, N), F_v_normalized, v)
    ratio = np.sum((v_selected >= (v_max - v_tol)) & (v_selected <= (v_max + v_tol))) / N
    return abs(ratio - r)

# Paramètres
alpha = 1.4
v_interval = 10  # Intervalle en pourcentage
r = 0.80  # Ratio cible
N = 5000  # Nombre de véhicules
k = 0.55  # Valeur de k entre 0 et 1

# Domaine de v_max
v_max_values = np.linspace(8, 140, 1000)
beta_values = np.zeros_like(v_max_values)

# Pré-calculer les valeurs constantes
v_tol_cache = v_interval / 100 * v_max_values
v_param_cache = v_max_values * (1.05 + 0.03 * k)

# Trouver beta pour chaque v_max
for i, v_max in enumerate(v_max_values):
    v_tol = v_tol_cache[i]
    v_param = v_param_cache[i] - (0.1 * alpha / (alpha + 1)) ** (1 / alpha)
    v = np.linspace(0.1, v_param, 10000)
    
    def func_to_optimize(beta):
        v_param = v_param_cache[i] - (beta * alpha / (alpha + 1)) ** (1 / alpha)
        v = np.linspace(0.1, v_param, 10000)
        g_v = (alpha * beta**alpha) / (v_param - v)**(alpha + 1) * np.exp(-beta * (v_param - v)**(-alpha))
        g_v = np.nan_to_num(g_v, nan=0.0, posinf=0.0, neginf=0.0)
        g_v_normalized = g_v / np.max(g_v)
        F_v = cumulative_trapezoid(g_v_normalized, v, initial=0)
        F_v_normalized = F_v / np.max(F_v)
        v_selected = np.interp(np.random.uniform(0, 1, N), F_v_normalized, v)
        ratio = np.sum((v_selected >= (v_max - v_tol)) & (v_selected <= (v_max + v_tol))) / N
        return abs(ratio - r)
    
    res = minimize_scalar(func_to_optimize, bounds=(0.1, 10), method='bounded')
    beta_values[i] = res.x

# Tracé de beta en fonction de v_max
plt.figure(figsize=(10, 6))
plt.plot(v_max_values, beta_values, marker='o', linestyle='-')
plt.xlabel('Vitesse maximale $v_{max}$ (km/h)')
plt.ylabel('Valeur de $\\beta$')
plt.title('Valeur de $\\beta$ pour obtenir un ratio de 80% de véhicules dans l\'intervalle $[v_{max} - v_{interval}, v_{max} + v_{interval}]$')
plt.grid(True)
plt.show()
