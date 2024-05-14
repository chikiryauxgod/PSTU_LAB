import numpy as np
import matplotlib.pyplot as plt
from ipywidgets import interact, FloatSlider

def move_point(x, y, k, l, n):
    # ���� ��������
    theta = np.pi / 4
    
    # ���������� ����� ��������� ����� ����� ��������������
    new_x = x * (np.cos(theta) + k) - y * (np.sin(theta) + k) + l * np.cos(theta) + k
    new_y = x * (np.sin(theta) + n) + y * (np.cos(theta) + n) + l * np.sin(theta) + n
    
    return new_x, new_y

# �������� ��������� ��������� �����
x_initial = 1
y_initial = 1

# �������� ������� ��� ������������ ����������� �����
def visualize_robot(k, l, n):
    # ����� ������� ��� ����������� �����
    x_new, y_new = move_point(x_initial, y_initial, k, l, n)
    
    # ������������ ��������� � �������� �����
    plt.figure(figsize=(8, 6))
    plt.plot(x_initial, y_initial, 'ro', label='��������� �����')
    plt.plot(x_new, y_new, 'bo', label='�������� �����')
    plt.xlabel('X')
    plt.ylabel('Y')
    plt.title('����������� ������')
    plt.legend()
    plt.grid(True)
    plt.axis('equal')
    plt.show()

# �������� ��������� ��� ��������� �������������
k_slider = FloatSlider(value=0.5, min=0, max=1, step=0.01, description='k:')
l_slider = FloatSlider(value=0.5, min=0, max=1, step=0.01, description='l:')
n_slider = FloatSlider(value=0.5, min=0, max=1, step=0.01, description='n:')

# ������������� �����������
interact(visualize_robot, k=k_slider, l=l_slider, n=n_slider);
