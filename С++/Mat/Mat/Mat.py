import numpy as np
import matplotlib.pyplot as plt

# Создаем комплексную сетку
x = np.linspace(-2, 3, 400)
y = np.linspace(-3, 2, 400)
X, Y = np.meshgrid(x, y)
Z = X + 1j*Y

# Определяем условия для областей
circle = np.abs(Z - (1 - 1j)) <= 1
below_line = Y <= -1
left_of_line = X < 1

# Отображаем области
plt.figure(figsize=(8, 6))

plt.imshow(circle, extent=(-2, 3, -3, 2), origin='lower', cmap='Blues', alpha=0.5)
plt.imshow(below_line, extent=(-2, 3, -3, 2), origin='lower', cmap='Greens', alpha=0.5)
plt.imshow(left_of_line, extent=(-2, 3, -3, 2), origin='lower', cmap='Oranges', alpha=0.5)

# Добавляем легенду
plt.legend(['Circle', 'Below Line', 'Left of Line'], loc='upper left')

# Добавляем заголовок и метки осей
plt.title('Regions in Complex Plane')
plt.xlabel('Re(z)')
plt.ylabel('Im(z)')

# Отображаем график
plt.grid(True)
plt.show()
