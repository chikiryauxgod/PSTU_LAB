import numpy as np
import matplotlib.pyplot as plt
from ipywidgets import interact, FloatSlider

def move_point(x, y, k, l, n):
    # Угол поворота
    theta = np.pi / 4
    
    # Вычисление новых координат точки после преобразования
    new_x = x * (np.cos(theta) + k) - y * (np.sin(theta) + k) + l * np.cos(theta) + k
    new_y = x * (np.sin(theta) + n) + y * (np.cos(theta) + n) + l * np.sin(theta) + n
    
    return new_x, new_y

# Создание начальных координат точки
x_initial = 1
y_initial = 1

# Создание функции для визуализации перемещения точки
def visualize_robot(k, l, n):
    # Вызов функции для перемещения точки
    x_new, y_new = move_point(x_initial, y_initial, k, l, n)
    
    # Визуализация начальной и конечной точек
    plt.figure(figsize=(8, 6))
    plt.plot(x_initial, y_initial, 'ro', label='Начальная точка')
    plt.plot(x_new, y_new, 'bo', label='Конечная точка')
    plt.xlabel('X')
    plt.ylabel('Y')
    plt.title('Перемещение робота')
    plt.legend()
    plt.grid(True)
    plt.axis('equal')
    plt.show()

# Создание ползунков для изменения коэффициентов
k_slider = FloatSlider(value=0.5, min=0, max=1, step=0.01, description='k:')
l_slider = FloatSlider(value=0.5, min=0, max=1, step=0.01, description='l:')
n_slider = FloatSlider(value=0.5, min=0, max=1, step=0.01, description='n:')

# Интерактивное отображение
interact(visualize_robot, k=k_slider, l=l_slider, n=n_slider);
