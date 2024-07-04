import numpy as np
import matplotlib.pyplot as plt

# Paramètres pour la distribution de Pareto inversée
alpha = 1.1
beta = 0.4
v_max = 30 # Vitesse maximale (m/s)
v_param = v_max - (beta * alpha / (alpha + 1)) ** (1 / alpha)

# Domaine de v
v = np.linspace(0, 1.5*v_max, 10000)

# Calcul de la densité de probabilité
g_v = 1/(1.2)*(alpha * beta**alpha) / (v_param - v)**(alpha + 1) * np.exp(-beta * (v_param - v)**(-alpha))

# Tracé de la distribution des vitesses
plt.figure(figsize=(14, 8))
plt.plot(v, g_v, color='blue')
plt.xlabel('Vitesse (m/s)')
plt.ylabel('Densité de Probabilité')
plt.title('Distribution des Vitesses Utilisant la Distribution de Pareto Inversée')
plt.show()