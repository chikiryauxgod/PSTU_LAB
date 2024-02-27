import numpy as np
import matplotlib.pyplot as plt

# Определение функции, возвращающей окружность с центром (x0, y0) и радиусом r
def circle(x0, y0, r):
    theta = np.linspace(0, 2*np.pi, 100)
    x = x0 + r * np.cos(theta)
    y = y0 + r * np.sin(theta)
    return x, y

# Создание массива значений для комплексной плоскости
x = np.linspace(-2, 4, 400)
y = np.linspace(-2, 4, 400)
X, Y = np.meshgrid(x, y)

# Вычисление модуля функции |z - 1|
modulus = np.abs(X + 1j*Y - 1)

# Построение графика
plt.figure(figsize=(8, 8))
plt.contour(X, Y, modulus, levels=[0.5], colors='r')  # Окружность |z - 1| = 1/2 красного цвета
plt.xlabel('Re(z)')
plt.ylabel('Im(z)')
plt.title('Contour |z - 1| = 1/2')
plt.grid(True)
plt.axis('equal')
plt.show()
