#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int* GenArray(int size) {
    int* array = (int*)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 20 - 10; 
    }
    return array;
}

int** GenMatrix(int rows, int cols) {
    int** matrix = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*)malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 20 - 10; 
        }
    }
    return matrix;
}

void PrintArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int* AddModul(int* arr, int* size) {
    int newSize = *size;
    for (int i = 0; i < *size; i++) {
        if (arr[i] < 0) {
            arr = (int*)realloc(arr, (newSize + 1) * sizeof(int));
            for (int j = newSize; j > i; j--) {
                arr[j] = arr[j - 1];
            }
            arr[i + 1] = abs(arr[i]);
            newSize++;
            i++; 
        }
    }
    *size = newSize;
    return arr;
}


void PrintMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int** RemoveEven(int** matrix, int* rows, int* cols) {
    for (int j = *cols - 1; j >= 0; j--) {
        if (j % 2 == 0) {
            for (int i = 0; i < *rows; i++) {
                for (int k = j; k < *cols - 1; k++) {
                    matrix[i][k] = matrix[i][k + 1];
                }
            }
            (*cols)--;
        }
    }
    return matrix;
}

int main() {
    setlocale(LC_ALL, "ru");
    srand(time(NULL));


    int size;
    printf("Введите размер одномерного массива: ");
    scanf_s("%d", &size);


    int* array = GenArray(size);


    printf("Исходный одномерный массив:\n");
    PrintArray(array, size);

    array = AddModul(array, &size);

    printf("Массив после добавления модулей:\n");
    PrintArray(array, size);

   
    free(array);


    int rows, cols;
    printf("Введите количество строк двумерного массива: ");
    scanf_s("%d", &rows);
    printf("Введите количество столбцов двумерного массива: ");
    scanf_s("%d", &cols);


    int** matrix = GenMatrix(rows, cols);


    printf("Исходный двумерный массив:\n");
    PrintMatrix(matrix, rows, cols);

 
    matrix = RemoveEven(matrix, &rows, &cols);


    printf("Массив после удаления четных столбцов:\n");
    PrintMatrix(matrix, rows, cols);


    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
