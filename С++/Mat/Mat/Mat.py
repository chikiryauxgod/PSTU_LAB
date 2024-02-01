import numpy as np
import matplotlib.pyplot as plt

def fourier_series(x, n_terms):
    result = np.pi - 2 * x
    for n in range(1, n_terms + 1, 2):
        result += (4 / (n**3 * np.pi)) * (1 - (-1)**n) * np.sin(n * x)
    return result

x_values = np.linspace(0, np.pi/2, 1000)
y_values = fourier_series(x_values, 5)

plt.plot(x_values, y_values, label='Approximate Sum (5 terms)')
plt.xlabel('x')
plt.ylabel('f(x)')
plt.title('Approximate Fourier Series for $f(x) = \pi - 2x$')
plt.legend()
plt.grid(True)
plt.show()
