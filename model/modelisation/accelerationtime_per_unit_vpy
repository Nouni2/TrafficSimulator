import numpy as np
import matplotlib.pyplot as plt

# Points donnés
v1, t1 = 30, 0.5
v2, t2 = 140, 2.7

# Calcul des paramètres v_ref et t0
v_ref = ((t2 * np.sqrt(v1) - t1 * np.sqrt(v2)) / (t2 - t1)) ** 2
t0 = t1 / (1 + np.sqrt(v1 / v_ref))

# Fonction pour t_acc_per_unit_v selon le modèle racine carrée
def t_acc_per_unit_v(v, t0, v_ref):
    return t0 * (1 + np.sqrt(v / v_ref))

# Domaine des vitesses en km/h
v_values = np.linspace(0, 160, 1000)
t_acc_per_unit_v_values = t_acc_per_unit_v(v_values, t0, v_ref)

# Tracé du modèle racine carrée
plt.figure(figsize=(10, 6))
plt.plot(v_values, t_acc_per_unit_v_values, label='$t_{acc\_per\_unit\_v} = t_0 (1 + \sqrt{v / v_{ref}})$')
plt.xlabel('Vitesse (km/h)')
plt.ylabel('$t_{acc\_per\_unit\_v}$ (s/km/h)')
plt.title('Modèle racine carrée pour $t_{acc\_per\_unit\_v}$')
plt.legend()
plt.grid(True)
plt.show()

print(f"v_ref = {v_ref:.2f} km/h")
print(f"t0 = {t0:.2f} s/km/h")
