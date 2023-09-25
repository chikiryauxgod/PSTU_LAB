import networkx as nx
import matplotlib.pyplot as plt

# Создаем пустой граф
zoo_graph = nx.Graph()

# Добавляем животных в зоопарк
zoo_graph.add_node("Белый медведь (умер)")
zoo_graph.add_node("Горные козлы")
zoo_graph.add_node("Обезьяны")
zoo_graph.add_node("Крокодилы")
zoo_graph.add_node("Горные козлы")
zoo_graph.add_node("Жирафы")
zoo_graph.add_node("Бабочки")
zoo_graph.add_node("Пеликаны")
zoo_graph.add_node("Бурый медведь")
zoo_graph.add_node("Лев")
zoo_graph.add_node("Бобры")
zoo_graph.add_node("Гималайский медведь")
zoo_graph.add_node("Муравьед")
zoo_graph.add_node("Ламы")
zoo_graph.add_node("Фламинго")


zoo_graph.add_edges_from([
    ("Белый медведь (умер)", "Обезьяны"),
    ("Белый медведь (умер)", "Пеликаны"),
    ("Белый медведь (умер)", "Горные козлы"),
    ("Белый медведь (умер)", "Муравьед"),
    ("Пеликаны", "Горные козлы"),
    ("Пеликаны", "Бабочки"),
    ("Пеликаны", "Бобры"),
    ("Бабочки", "Бурый медведь"),
    ("Бурый медведь", "Азиатский лев"),
    ("Азиатский лев", "Лев"),
    ("Лев", "Амурский тигр"),
    ("Лев", "Гималайский медведь"),
    ("Амурский тигр", "Гималайский медведь"),
    ("Бурый медведь", "Жирафы"),
    ("Азиатский лев", "Жирафы"),
    ("Горные козлы", "Жирафы"),
    ("Обезьяны", "Крокодилы"),
    ("Муравьед", "Фламинго"),
    ("Муравьед", "Бобры"),
    ("Муравьед", "Фламинго"),
    ("Бобры", "Фламинго"),
    ("Муравьед", "Ламы"),
])




def get_neighbors(animal):
    neighbors = list(zoo_graph.neighbors(animal))
    return neighbors

# Визуализация графа
pos = nx.spring_layout(zoo_graph)
plt.figure(figsize=(10, 8))
nx.draw(zoo_graph, pos, with_labels=True, node_size=500, node_color='lightblue', font_size=10, font_color='black', font_weight='bold', edge_color='gray')
plt.title("Структурный зоопарк")
plt.show()

# Вводимое животное
input_animal = input("Введите имя животного: ")

# Получаем соседей введенного животного
neighbors = get_neighbors(input_animal)
if neighbors:
    print(f"Соседи у {input_animal}: {neighbors}")
else:
    print(f"{input_animal} не найден в зоопарке.")