import numpy as np
import matplotlib.pyplot as plt

# Paramètres de la distribution normale
mu = 1.0
sigma = 0.1
g = 9.81  # m/s^2
mu_road = 0.7  # coefficient de friction sans unité

# Valeurs de courbure (inverse du rayon de courbure) en 1/m
kappa_values = np.linspace(0.01, 0.5, 5)  # Courbures de plus en plus serrées

# Génération de la variable aléatoire gaussienne
num_samples = 1000
X_samples = np.random.normal(mu, sigma, num_samples)

# Calcul de v_max,courbure pour chaque courbure en m/s, puis conversion en km/h
v_max_curvature_distributions = []
for kappa in kappa_values:
    v_max_curvature = np.sqrt((mu_road * g * X_samples) / kappa) * 3.6  # Conversion m/s to km/h
    v_max_curvature_distributions.append(v_max_curvature)

# Tracé des distributions
plt.figure(figsize=(14, 8))
for i, kappa in enumerate(kappa_values):
    plt.hist(v_max_curvature_distributions[i], bins=50, alpha=0.6, label=f'R = {kappa**(-1):.2f} m')

plt.xlabel('v_max,courbure (km/h)')
plt.ylabel('Frequency')
plt.title('Distribution of v_max,courbure for Different Curvatures')
plt.legend()
plt.grid(True)
plt.show()
