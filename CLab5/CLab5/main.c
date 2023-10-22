#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void GenArr(int arr[], int length) {
    for (int i = 0; i < length; i++) {
        arr[i] = rand() % 100 - 49;
    }
}

void PrintArr(int arr[], int length) {
    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int* NegativeModul(int arr[], int* length) {
    int n = *length; // Инициализируем n текущим значением длины массива
    for (int i = 0; i < *length; i++) {
        if (arr[i] < 0) {
            n++; // Увеличиваем n, если элемент отрицателен
        }
    }

    // Создаем новый массив, большего размера
    int* newArr = (int*)malloc(n * sizeof(int));
    if (newArr == NULL) {
        fprintf(stderr, "Ошибка выделения памяти.\n");
        exit(1);
    }

    int newI = 0;
    for (int i = 0; i < *length; i++) {
        if (arr[i] < 0) {
            newArr[newI++] = abs(arr[i]); // Если элемент отрицателен, добавляем его модуль
        }
        newArr[newI++] = arr[i];
    }

    free(arr); // Освобождаем память старого массива
    *length = n; // Обновляем значение длины

    return newArr; // Возвращаем новый массив
}

void GenMatrix(int*** matrix, int rows, int cols) {
    *matrix = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        (*matrix)[i] = (int*)malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            (*matrix)[i][j] = rand() % 100 - 49;
        }
    }
}

void PrintMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

int** NoEven(int** matrix, int* rows, int* cols) {
    int newCols = *cols / 2; // Вычисляем новое количество столбцов
    int** newMatrix = (int**)malloc(*rows * sizeof(int*));

    for (int i = 0; i < *rows; i++) {
        newMatrix[i] = (int*)malloc(newCols * sizeof(int));
        int newIndex = 0;

        for (int j = 0; j < *cols; j++) {
            if (j % 2 == 0) { // Оставляем только нечетные столбцы (изменено с 1 на 0)
                for (int k = 0; k < *rows; k++) {
                    newMatrix[k][newIndex] = matrix[k][j];
                }
                newIndex++;
            }
        }
    }

    for (int i = 0; i < *rows; i++) {
        free(matrix[i]); // Освобождаем память старой матрицы
    }
    free(matrix);

    *cols = newCols; // Обновляем значение числа столбцов
    return newMatrix; // Возвращаем новую матрицу
}

int main() {
    setlocale(LC_ALL, "ru");
    int arrlength;

    do {
        printf("Введите размер массива: ");
        scanf("%d", &arrlength);

        if (arrlength <= 0) {
            printf("Размер массива должен быть больше нуля.\n");
        }
    } while (arrlength <= 0);

    int* arr = (int*)malloc(arrlength * sizeof(int));

    if (arr == NULL) {
        fprintf(stderr, "Ошибка выделения памяти.\n");
        return 1;
    }

    GenArr(arr, arrlength);
    printf("Исходный массив: ");
    PrintArr(arr, arrlength);

    int* modedArr = NegativeModul(arr, &arrlength);
    printf("Массив с добавленными модулями: ");
    PrintArr(modedArr, arrlength);
    free(modedArr);

    int matrows, matcols;

    do {
        printf("Введите количество строк матрицы: ");
        scanf("%d", &matrows);

        if (matrows <= 0) {
            printf("Количество строк должно быть больше нуля.\n");
        }
    } while (matrows <= 0);

    do {
        printf("Введите количество столбцов матрицы: ");
        scanf("%d", &matcols);

        if (matcols <= 0) {
            printf("Количество столбцов должно быть больше нуля.\n");
        }
    } while (matcols <= 0);

    int** matrix;
    GenMatrix(&matrix, matrows, matcols);
    printf("Исходная матрица:\n");
    PrintMatrix(matrix, matrows, matcols);

    int** modedMatrix = NoEven(matrix, &matrows, &matcols);
    printf("Матрица без четных столбцов:\n");
    PrintMatrix(modedMatrix, matrows, matcols);

    for (int i = 0; i < matrows; i++) {
        free(modedMatrix[i]);
    }

    free(modedMatrix);

    return 0;
}
