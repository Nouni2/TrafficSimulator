import numpy as np
import matplotlib.pyplot as plt

# Paramètres communs pour la distribution de Pareto inversée
v_max = 100 # Vitesse maximale (m/s)
v = np.linspace(0, 1.5 * v_max, 10000)  # Domaine des vitesses
k = 0.55  # Valeur de k entre 0 et 1

# Variation de beta avec alpha fixé à 1.1
def plot_betas():
    alpha = 1.1  # Alpha est une valeur empirique à ne surtout pas changer
    betas = [1,2,3,4,5,6,7,8,9,10]
    
    plt.figure(figsize=(14, 8))
    
    for beta in betas:
        # Calcul de v_param dépendant de beta et alpha
        v_param = v_max * (1.05 + 0.03 * k) - (beta * alpha / (alpha + 1)) ** (1 / alpha)
        
        # Calcul de la densité de probabilité
        g_v = (alpha * beta**alpha) / (v_param - v)**(alpha + 1) * np.exp(-beta * (v_param - v)**(-alpha))
        g_v /= max(g_v)  # Normalisation
        
        plt.plot(v, g_v, label=f'β = {beta}')
    
    plt.xlabel('Vitesse (m/s)')
    plt.ylabel('Densité de Probabilité')
    plt.grid(True, which='both', linestyle='--', linewidth=0.5)
    plt.title('Distribution des Vitesses Utilisant la Distribution de Pareto Inversée pour Différentes Valeurs de Beta')
    plt.legend()
    plt.show()

# Exemple d'appel pour tracer la variation de beta avec alpha fixé
plot_betas()

# Effet de beta sur la distribution
# Beta joue un rôle crucial dans la forme de la distribution :
# - Un beta petit (0.2) produit une courbe de densité de probabilité plus concentrée et étroite autour de v_max,
#   ce qui indique une distribution plus serrée des vitesses près de la valeur maximale.
# - Un beta grand (0.8) élargit la distribution et augmente le volume sous la courbe près de v_max,
#   ce qui signifie que les vitesses sont plus dispersées et qu'il y a une plus grande probabilité de trouver des vitesses
#   légèrement inférieures à v_max.
