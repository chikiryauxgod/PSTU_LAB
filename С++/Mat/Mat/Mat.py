import numpy as np
import matplotlib.pyplot as plt

# ����������� �������, ������������ ���������� � ������� (x0, y0) � �������� r
def circle(x0, y0, r):
    theta = np.linspace(0, 2*np.pi, 100)
    x = x0 + r * np.cos(theta)
    y = y0 + r * np.sin(theta)
    return x, y

# �������� ������� �������� ��� ����������� ���������
x = np.linspace(-2, 4, 400)
y = np.linspace(-2, 4, 400)
X, Y = np.meshgrid(x, y)

# ���������� ������ ������� |z - 1|
modulus = np.abs(X + 1j*Y - 1)

# ���������� �������
plt.figure(figsize=(8, 8))
plt.contour(X, Y, modulus, levels=[0.5], colors='r')  # ���������� |z - 1| = 1/2 �������� �����
plt.xlabel('Re(z)')
plt.ylabel('Im(z)')
plt.title('Contour |z - 1| = 1/2')
plt.grid(True)
plt.axis('equal')
plt.show()
