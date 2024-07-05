import numpy as np
import matplotlib.pyplot as plt
from scipy.stats import beta, norm

# Parameters for the distributions
mu_t = 1.5  # mean reaction time (seconds)
sigma_t = 0.5  # standard deviation of reaction time (seconds)
alpha1, beta1 = 2, 5  # parameters for the Beta distribution of k1
alpha2, beta2 = 5, 2  # parameters for the Beta distribution of k2

# Generate random samples for reaction time and coefficients
t_reaction_samples = norm.rvs(loc=mu_t, scale=sigma_t, size=3000)
k1_samples = beta.rvs(alpha1, beta1, size=3000)
k2_samples = beta.rvs(alpha2, beta2, size=3000)

# Fixed parameters
v_samples = np.linspace(10, 30, 3000)  # speed (m/s)
a_deceleration = 3  # maximum deceleration (m/s^2)
d = 50  # actual distance between vehicles (m)
v_B = 25  # speed of the vehicle in front (m/s)
v_A = 20  # speed of the vehicle behind (m/s)
delta_v = v_B - v_A

# Calculate d_safety
d_safety_samples = v_samples * t_reaction_samples + v_samples**2 / (2 * a_deceleration)

# Calculate a_adapt for different k1 and k2 samples
a_adapt_samples = k1_samples * ((d - d_safety_samples) / d_safety_samples) + k2_samples * delta_v

# Plotting
plt.figure(figsize=(14, 8))

plt.title('$a_{adapt}$ (m/s^2) as a function of different parameters')

# Plot a_adapt vs k1
plt.subplot(2, 2, 1)
plt.scatter(k1_samples, a_adapt_samples, alpha=0.5, s=10, color='blue')
plt.xlabel('$k_1$')
plt.ylabel('$a_{adapt}$')
plt.title('$a_{adapt}$ vs $k_1$')

# Plot a_adapt vs k2
plt.subplot(2, 2, 2)
plt.scatter(k2_samples, a_adapt_samples, alpha=0.5, s=10, color='green')
plt.xlabel('$k_2$')
plt.ylabel('$a_{adapt}$')
plt.title('$a_{adapt}$ vs $k_2$')

# Plot a_adapt vs t_reaction
plt.subplot(2, 2, 3)
plt.scatter(t_reaction_samples, a_adapt_samples, alpha=0.5, s=10, color='red')
plt.xlabel('$t_{reaction}$ (s)')
plt.ylabel('$a_{adapt}$')
plt.title('$a_{adapt}$ vs $t_{reaction}$')

# Plot a_adapt vs v
plt.subplot(2, 2, 4)
plt.scatter(v_samples*3.6, a_adapt_samples, alpha=0.5, s=10, color='purple')
plt.xlabel('$v$ (km/h)')
plt.ylabel('$a_{adapt}$')
plt.title('$a_{adapt}$ vs $v$')

plt.tight_layout()
plt.show()
