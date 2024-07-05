import numpy as np
import matplotlib.pyplot as plt
from scipy.integrate import cumulative_trapezoid
from scipy.optimize import minimize_scalar
from sklearn.ensemble import RandomForestRegressor
from sklearn.metrics import mean_squared_error, mean_absolute_error, r2_score
from sklearn.model_selection import train_test_split
import pandas as pd

# Fonction pour calculer le ratio des véhicules dans l'intervalle de tolérance
def compute_ratio(beta, alpha, v_max, v_interval, N, r, k):
    v_tol = v_interval / 100 * v_max
    v_param = v_max * (1.05 + 0.03 * k) - (beta * alpha / (alpha + 1)) ** (1 / alpha)
    v = np.linspace(0.1, v_param, 10000)
    epsilon = 1e-10  # Petite valeur pour éviter les divisions par zéro
    g_v = (alpha * beta**alpha) / (v_param - v + epsilon)**(alpha + 1) * np.exp(-beta * (v_param - v + epsilon)**(-alpha))
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
r_values = np.linspace(0.7, 0.9, 10)  # Différentes valeurs de r
N = 5000  # Nombre de véhicules
k = 0.55  # Valeur de k entre 0 et 1

# Domaine de v_max
v_max_values = np.linspace(8, 240, 50)
beta_values = []

# Collecter les données
for v_max in v_max_values:
    for r in r_values:
        res = minimize_scalar(compute_ratio, args=(alpha, v_max, v_interval, N, r, k), bounds=(0.1, 10), method='bounded')
        beta_values.append((v_max, r, res.x))

# Conversion des données en numpy array
beta_values = np.array(beta_values)

# Sauvegarde des valeurs de beta dans un fichier CSV
df = pd.DataFrame(beta_values, columns=['v_max', 'r', 'beta'])
df.to_csv('beta_values.csv', index=False)

# Lecture des valeurs de beta depuis le fichier CSV
df_loaded = pd.read_csv('beta_values.csv')
print(df_loaded.head())

# Séparation des données pour l'entraînement et le test
X = df_loaded[['v_max', 'r']].values
y = df_loaded['beta'].values
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

# Modèle de forêt aléatoire
model = RandomForestRegressor(n_estimators=100, random_state=42)
model.fit(X_train, y_train)

# Prédictions sur l'ensemble de test
y_pred = model.predict(X_test)

# Calcul des métriques de validation
mse = mean_squared_error(y_test, y_pred)
mae = mean_absolute_error(y_test, y_pred)
r2 = r2_score(y_test, y_pred)

# Affichage des résultats de la régression et des métriques
print("Mean Squared Error (MSE) sur l'ensemble de test : ", mse)
print("Mean Absolute Error (MAE) sur l'ensemble de test : ", mae)
print("Coefficient de détermination (R^2) sur l'ensemble de test : ", r2)

# Visualisation des résultats sur l'ensemble de test
fig = plt.figure(figsize=(12, 8))
ax = fig.add_subplot(111, projection='3d')
ax.scatter(X_test[:, 0], X_test[:, 1], y_test, color='blue', label='Données réelles')
ax.scatter(X_test[:, 0], X_test[:, 1], y_pred, color='red', label='Prédictions')
ax.set_xlabel('Vitesse maximale $v_{max}$ (km/h)')
ax.set_ylabel('Ratio cible $r$')
ax.set_zlabel('Valeur de $\\beta$')
ax.set_title('Modèle de forêt aléatoire pour $\\beta$ en fonction de $v_{max}$ et $r$ (Ensemble de test)')
plt.legend()
plt.show()
