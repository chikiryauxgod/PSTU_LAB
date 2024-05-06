import numpy as np

class Vertex:
    def __init__(self, x, y, z):
        self.x = x
        self.y = y
        self.z = z

class Triangle:
    def __init__(self, v1, v2, v3):
        self.vertices = [v1, v2, v3]

def render_triangles(triangles, screen_width, screen_height):
    # Создаем Z-буфер, инициализированный очень большими значениями
    z_buffer = np.full((screen_height, screen_width), float('inf'))

    # Создаем экран (пиксельный буфер)
    frame_buffer = np.zeros((screen_height, screen_width, 3), dtype=np.uint8)  # для RGB

    for tri in triangles:
        # Рисуем каждый треугольник
        for v in tri.vertices:
            # Проекция вершины на экран (здесь используется очень простая проекция)
            x = int((v.x + 1) * screen_width / 2)
            y = int((v.y + 1) * screen_height / 2)
            z = v.z

            # Проверка Z-буфера и обновление экрана
            if 0 <= x < screen_width and 0 <= y < screen_height:
                if z < z_buffer[y][x]:
                    z_buffer[y][x] = z
                    # Устанавливаем цвет пикселя (здесь всегда белый для упрощения)
                    frame_buffer[y][x] = [255, 255, 255]

    return frame_buffer

# Пример использования
vertices = [Vertex(-0.5, -0.5, 0.5), Vertex(0.5, -0.5, 0.5), Vertex(0.0, 0.5, 0.5)]
triangle = Triangle(vertices[0], vertices[1], vertices[2])
triangles = [triangle]

screen_width = 100
screen_height = 100
image = render_triangles(triangles, screen_width, screen_height)

# Отображаем или сохраняем результат
import matplotlib.pyplot as plt
plt.imshow(image)
plt.show()
