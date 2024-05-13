import matplotlib.pyplot as plt

kamaz = {'points': 39, 'production': 53000}
gaz = {'points': 31, 'production': 53000}

brands = ['КАМАЗ', 'ГАЗ']
points = [kamaz['points'], gaz['points']]
production = [kamaz['production'], gaz['production']]

plt.figure(figsize=(10, 6))
plt.plot(production, points, marker='o', linestyle='-', color='b')
plt.title('График зависимости результатов сравнения')
plt.xlabel('Продукция')
plt.ylabel('Баллы')
plt.xticks(rotation=45)
plt.grid(True)

for i in range(len(brands)):
    plt.text(production[i], points[i], brands[i])

plt.tight_layout()
plt.show()
