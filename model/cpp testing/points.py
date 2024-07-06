import matplotlib.pyplot as plt

# Lire les points du fichier
points = []
with open('data/points.txt', 'r') as file:
    for line in file:
        x, y = map(float, line.split())
        points.append((x, y))

# Séparer les coordonnées x et y
x_coords, y_coords = zip(*points)

# Tracer les points
plt.figure(figsize=(8, 8))
plt.plot(x_coords, y_coords, 'bo-')  # points bleus avec ligne
plt.gca().set_aspect('equal', adjustable='box')
plt.title('Points sur la circonférence d\'un cercle')
plt.xlabel('x')
plt.ylabel('y')
plt.grid(True)
plt.show()
