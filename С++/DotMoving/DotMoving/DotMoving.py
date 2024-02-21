import tkinter as tk
from tkinter import simpledialog
import numpy as np

def apply_transformation(point, a, k, n, l):
    # Матрица преобразования
    a = np.deg2rad(a)
    transformation_matrix = np.array([[np.cos(a) + k*np.sin(a) + n, 0, 0],
                                      [-np.sin(a) + k*np.cos(a) + n, 0, 0],
                                      [l*np.cos(a) + k*l*np.sin(a) + n, 0, 1]])

    # Умножение исходной точки на матрицу преобразования
    transformed_point = np.dot(transformation_matrix, point)
    return transformed_point

def draw_point(canvas, point):
    canvas.delete("all")
    x, y, _ = point.flatten()
    canvas.create_oval(x - 3, y - 3, x + 3, y + 3, fill="red")

def draw_coordinate_system(canvas, width, height):
    # Рисуем ось X
    canvas.create_line(0, height/2, width, height/2, fill="black", arrow=tk.LAST)
    # Рисуем ось Y
    canvas.create_line(width/2, 0, width/2, height, fill="black", arrow=tk.LAST)
    # Подписываем оси
    canvas.create_text(width - 10, height/2 - 10, text="X", anchor="se")
    canvas.create_text(width/2 + 10, 10, text="Y", anchor="nw")

def get_parameters():
    # Создаем отдельное окно для запроса параметров
    dialog = tk.Toplevel()
    dialog.title("Input Parameters")

    a = simpledialog.askfloat("Input", "Enter the angle (in degrees):", parent=dialog)
    k = simpledialog.askfloat("Input", "Enter the value of k:", parent=dialog)
    n = simpledialog.askfloat("Input", "Enter the value of n:", parent=dialog)
    l = simpledialog.askfloat("Input", "Enter the value of l:", parent=dialog)

    dialog.destroy()  # Закрываем диалоговое окно после получения параметров
    return a, k, n, l

def main():
    # Создаем графическое окно
    root = tk.Tk()
    root.title("Point Transformation")

    # Получаем параметры преобразования
    a, k, n, l = get_parameters()

    # Создаем холст для отображения точки и системы координат
    canvas_width = 800
    canvas_height = 800
    canvas = tk.Canvas(root, width=canvas_width, height=canvas_height, bg="white")
    canvas.pack()

    # Нарисуем систему координат
    draw_coordinate_system(canvas, canvas_width, canvas_height)

    # Задаем исходную точку
    point = np.array([[canvas_width/2], [canvas_height/2], [1]])

    # Применяем преобразование к исходной точке
    transformed_point = apply_transformation(point, a, k, n, l)

    # Получаем координаты преобразованной точки
    x, y, _ = transformed_point.flatten()

    # Пересчитываем координаты системы координат, чтобы точка оставалась видимой
    max_coord = max(abs(x), abs(y))
    canvas.scale(tk.ALL, 0, 0, canvas_width / (2 * max_coord), canvas_height / (2 * max_coord))

    # Отображаем точку на холсте
    draw_point(canvas, transformed_point)

    root.mainloop()

if __name__ == "__main__":
    main()
