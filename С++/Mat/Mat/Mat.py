import numpy as np
import matplotlib.pyplot as plt

# Создаем данные для построения окружности
theta = np.linspace(0, 2*np.pi, 100)
x = 0.5 + 0.5 * np.cos(theta)
y = np.sqrt(-x**2 + x)  # Мы решаем уравнение y = sqrt(-x^2 + x)

# Изображаем окружность
plt.figure(figsize=(6, 6))
plt.plot(x, y, label=r'$x^2 - x + y^2 = 0$')
plt.plot(x, -y, linestyle='--')  # Отобразим нижнюю половину окружности
plt.xlabel('Re')
plt.ylabel('Im')
plt.title('Окружность $x^2 - x + y^2 = 0$')
plt.gca().set_aspect('equal', adjustable='box')  # Установим соотношение масштабов осей
plt.grid(True)
plt.legend()
plt.show()
