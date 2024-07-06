import numpy as np
import matplotlib.pyplot as plt
import matplotlib.cm as cm

# Fonction pour calculer k_j
def calculate_k_j(vehicle_length, min_spacing):
    """
    Calculate the jam density k_j based on vehicle length and minimum spacing.
    
    Parameters:
    vehicle_length (float): The average length of vehicles in meters.
    min_spacing (float): The minimum spacing between vehicles in meters.
    
    Returns:
    float: The jam density in vehicles per meter.
    """
    k_j = 1 / (vehicle_length + min_spacing)
    return k_j

# Fonction pour calculer l'espacement minimum entre les véhicules en fonction de la vitesse
def spacing(v): 
    t_reac = 1.5 # Temps de réaction (s)
    a = 4 # Décélération maximale (m/s^2)
    return v * t_reac + (v**2) / (2 * a)

# Paramètres de la simulation
vehicle_length = 3.5  # Longueur moyenne des véhicules en mètres
capacity_factor = 0.8  # Facteur de capacité
v_f = 130 / 3.6  # Vitesse de libre circulation en m/s (converti de 130 km/h)
p_values = [0.25, 0.5, 1, 1.5, 2, 3]  # Différentes valeurs de p 

# Générer automatiquement les couleurs en fonction du nombre de valeurs de p
colors = plt.get_cmap('tab20')(np.linspace(0, 1, len(p_values)))

# Initialiser le graphique
fig, ax1 = plt.subplots(figsize=(12, 8))

# Calculer et tracer la densité et le flow rate pour différentes valeurs de p
for i, p in enumerate(p_values):
    # Calculer les valeurs de densité k
    k = np.linspace(0, 1 / (vehicle_length + spacing(v_f)), 1000)
    
    # Recalculer k_j pour chaque valeur de k
    k_j = calculate_k_j(vehicle_length, spacing(v_f))
    
    # Calculer la vitesse v
    v = v_f * (1 - (k / k_j)**p)
    
    # Calculer le flow rate q
    q = k * v

    # Tracer la densité k en fonction de la vitesse v
    ax1.plot(v * 3.6, k * 1000, label=f'p={p} (Densité)', color=colors[i])
    ax1.set_xlabel('Vitesse (km/h)')
    ax1.set_ylabel('Densité (veh/km)', color='black')
    ax1.tick_params(axis='y', labelcolor='black')
    ax1.grid(True)

# Ajouter l'axe secondaire pour le flow rate
ax2 = ax1.twinx()
for i, p in enumerate(p_values):
    # Calculer les valeurs de densité k
    k = np.linspace(0, 1 / (vehicle_length + spacing(v_f)), 1000)
    
    # Recalculer k_j pour chaque valeur de k
    k_j = calculate_k_j(vehicle_length, spacing(v_f))
    
    # Calculer la vitesse v
    v = v_f * (1 - (k / k_j)**p)
    
    # Calculer le flow rate q
    q = k * v
    
    # Tracer le flow rate q en fonction de la vitesse v en utilisant une échelle logarithmique
    ax2.plot(v * 3.6, q * 3600, label=f'p={p} (Flow Rate)', linestyle='dashed', color=colors[i])
    ax2.set_ylabel('Flow rate (veh/h)', color='black')
    ax2.tick_params(axis='y', labelcolor='black')

# Ajuster les marges pour le titre
plt.subplots_adjust(top=0.9)

# Ajouter des légendes et afficher le graphique
fig.tight_layout(rect=[0, 0, 1, 0.95])
fig.legend(loc='upper left', bbox_to_anchor=(0.1, 0.9))
plt.title('Densité et Flow Rate en fonction de la vitesse pour différentes valeurs de p')
plt.show()
