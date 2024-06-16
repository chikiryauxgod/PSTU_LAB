from scipy.integrate import quad

# Определяем функцию плотности вероятности для нормального распределения
def normal_pdf(x, mu, sigma):
    return 1 / (sigma * np.sqrt(2 * np.pi)) * np.exp(-0.5 * ((x - mu) / sigma)**2)

# Определяем параметры нормального распределения
mu = 5
sigma = 1

# Определяем интервалы для вычисления вероятностей
interval_1 = (2, 8)
interval_2 = (mu - 3, mu + 3)

# Вычисляем вероятности
probability_1, _ = quad(normal_pdf, *interval_1, args=(mu, sigma))
probability_2, _ = quad(normal_pdf, *interval_2, args=(mu, sigma))

print("Вероятность, что X примет значение в интервале 2 <= X <= 8:", probability_1)
print("Вероятность неравенства |X - 5| < 3:", probability_2)
