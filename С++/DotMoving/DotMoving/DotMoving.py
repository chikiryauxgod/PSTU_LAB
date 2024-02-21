import tkinter as tk
from tkinter import simpledialog
import numpy as np

def apply_transformation(point, a, k, n, l):
    # ������� ��������������
    a = np.deg2rad(a)
    transformation_matrix = np.array([[np.cos(a) + k*np.sin(a) + n, 0, 0],
                                      [-np.sin(a) + k*np.cos(a) + n, 0, 0],
                                      [l*np.cos(a) + k*l*np.sin(a) + n, 0, 1]])

    # ��������� �������� ����� �� ������� ��������������
    transformed_point = np.dot(transformation_matrix, point)
    return transformed_point

def draw_point(canvas, point):
    canvas.delete("all")
    x, y, _ = point.flatten()
    canvas.create_oval(x - 3, y - 3, x + 3, y + 3, fill="red")

def draw_coordinate_system(canvas, width, height):
    # ������ ��� X
    canvas.create_line(0, height/2, width, height/2, fill="black", arrow=tk.LAST)
    # ������ ��� Y
    canvas.create_line(width/2, 0, width/2, height, fill="black", arrow=tk.LAST)
    # ����������� ���
    canvas.create_text(width - 10, height/2 - 10, text="X", anchor="se")
    canvas.create_text(width/2 + 10, 10, text="Y", anchor="nw")

def get_parameters():
    # ������� ��������� ���� ��� ������� ����������
    dialog = tk.Toplevel()
    dialog.title("Input Parameters")

    a = simpledialog.askfloat("Input", "Enter the angle (in degrees):", parent=dialog)
    k = simpledialog.askfloat("Input", "Enter the value of k:", parent=dialog)
    n = simpledialog.askfloat("Input", "Enter the value of n:", parent=dialog)
    l = simpledialog.askfloat("Input", "Enter the value of l:", parent=dialog)

    dialog.destroy()  # ��������� ���������� ���� ����� ��������� ����������
    return a, k, n, l

def main():
    # ������� ����������� ����
    root = tk.Tk()
    root.title("Point Transformation")

    # �������� ��������� ��������������
    a, k, n, l = get_parameters()

    # ������� ����� ��� ����������� ����� � ������� ���������
    canvas_width = 800
    canvas_height = 800
    canvas = tk.Canvas(root, width=canvas_width, height=canvas_height, bg="white")
    canvas.pack()

    # �������� ������� ���������
    draw_coordinate_system(canvas, canvas_width, canvas_height)

    # ������ �������� �����
    point = np.array([[canvas_width/2], [canvas_height/2], [1]])

    # ��������� �������������� � �������� �����
    transformed_point = apply_transformation(point, a, k, n, l)

    # �������� ���������� ��������������� �����
    x, y, _ = transformed_point.flatten()

    # ������������� ���������� ������� ���������, ����� ����� ���������� �������
    max_coord = max(abs(x), abs(y))
    canvas.scale(tk.ALL, 0, 0, canvas_width / (2 * max_coord), canvas_height / (2 * max_coord))

    # ���������� ����� �� ������
    draw_point(canvas, transformed_point)

    root.mainloop()

if __name__ == "__main__":
    main()
