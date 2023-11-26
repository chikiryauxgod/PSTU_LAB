#include <stdio.h>
#include <time.h>
#include <locale.h>
#include <stdlib.h> 
#include <string.h>
#include <Windows.h>

// Функция для заполнения массива случайными числами
void GenArr(int arr[], int length) {
    for (int i = 0; i < length; i++) {
        arr[i] = rand() % 100-49;
    }
}

// Функция для вывода массива
void PrintArr(int arr[], int length) {
    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Функция для проверки, является ли число числом Фибоначчи
int IsFibonacci(int num) {
    if (num == 0 || num == 1) {
        return 1;
    }

    int a = 0, b = 1, c;
    while (b < num) {
        c = a + b;
        a = b;
        b = c;
    }

    return (b == num); // Возвращает 1, если число - число Фибоначчи, иначе 0
}

// Функция для нахождения и вывода чисел Фибоначчи в массиве
void FindFibonacci(int arr[], int length) {
    printf("Числа Фибоначчи в массиве: ");
    for (int i = 0; i < length; i++) {
        if (IsFibonacci(arr[i])) {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
}

// Функция для генерации случайных значений матрицы и выделения памяти
void GenMatrix(int*** matrix, int rows, int cols) {
    *matrix = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        (*matrix)[i] = (int*)malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            (*matrix)[i][j] = rand() % 100-49;
        }
    }
}
// Функция для вывода матрицы
void PrintMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

// Функция для сортировки матрицы по убыванию
void SortMatrix(int** matrix, int rows, int cols) {
    for (int j = 0; j < cols; j++) {
        for (int i = 0; i < rows - 1; i++) {
            for (int k = 0; k < rows - i - 1; k++) {
                if (matrix[k][j] < matrix[k + 1][j]) {
                    // Обмен элементов
                    int temp = matrix[k][j];
                    matrix[k][j] = matrix[k + 1][j];
                    matrix[k + 1][j] = temp;
                }
            }
        }
    }
}

// Функция для ввода строки
void InpString(char* str, int max_length) {
    printf("Введите строку (максимум %d символов): ", max_length - 1);
    fgets(str, max_length, stdin);
    str[strcspn(str, "\n")] = '\0';
}

void PrintString(const char* str) {
    printf("Введенная строка: %s\n", str);
}

// Функция для подсчета количества слов в строке
int Words(const char* str) {
    int word_count = 0;
    int inside = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ' || str[i] == '\t') {
            inside = 0;
        }
        else {
            if (!inside) {
                word_count++;
                inside = 1;
            }
        }
    }
    return word_count;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "ru");
    srand(time(NULL));

    int arrlength;
    do {
        printf("Введите размер массива: ");
        scanf_s("%d", &arrlength);

        if (arrlength <= 0) {
            printf("Размер массива должен быть больше нуля.\n");
        }
    } while (arrlength <= 0);

    // Выделение памяти для массива
    int* array = (int*)malloc(arrlength * sizeof(int));
    GenArr(array, arrlength);

    printf("Сгенерированный массив: ");
    PrintArr(array, arrlength);

    FindFibonacci(array, arrlength);

    int matrows, matcols;
    do {
        printf("Введите количество строк матрицы: ");
        scanf_s("%d", &matrows);

        if (matrows <= 0) {
            printf("Количество строк должно быть больше нуля.\n");
        }
        getchar(); // Очистка входного буфера
    } while (matrows <= 0);

    do {
        printf("Введите количество столбцов матрицы: ");
        scanf_s("%d", &matcols);

        if (matcols <= 0) {
            printf("Количество столбцов должно быть больше нуля.\n");
        }
        getchar(); // Очистка входного буфера
    } while (matcols <= 0);

    // Выделение памяти для матрицы
    int** matrix;
    GenMatrix(&matrix, matrows, matcols);

    printf("Сгенерированная матрица:\n");
    PrintMatrix(matrix, matrows, matcols);
    SortMatrix(matrix, matrows, matcols); // Сортировка матрицы
    printf("Отсортированная матрица:\n");
    PrintMatrix(matrix, matrows, matcols);

    // Ввод и вывод строки
    char inputString[100]; // Максимальная длина строки 100 символов
    InpString(inputString, sizeof(inputString));
    PrintString(inputString);
    // Подсчет количества слов в строке
    int wordCount = Words(inputString);
    printf("Количество слов в строке: %d\n", wordCount);

    // Освобождение памяти перед завершением программы
    free(array);
    return 0;
}
