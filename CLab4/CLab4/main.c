#include <stdio.h>
#include <time.h>
#include <locale.h>
#include <stdlib.h> 
#include <string.h>
#include <Windows.h>

// ������� ��� ���������� ������� ���������� �������
void GenArr(int arr[], int length) {
    for (int i = 0; i < length; i++) {
        arr[i] = rand() % 100-49;
    }
}

// ������� ��� ������ �������
void PrintArr(int arr[], int length) {
    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// ������� ��� ��������, �������� �� ����� ������ ���������
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

    return (b == num); // ���������� 1, ���� ����� - ����� ���������, ����� 0
}

// ������� ��� ���������� � ������ ����� ��������� � �������
void FindFibonacci(int arr[], int length) {
    printf("����� ��������� � �������: ");
    for (int i = 0; i < length; i++) {
        if (IsFibonacci(arr[i])) {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
}

// ������� ��� ��������� ��������� �������� ������� � ��������� ������
void GenMatrix(int*** matrix, int rows, int cols) {
    *matrix = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        (*matrix)[i] = (int*)malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            (*matrix)[i][j] = rand() % 100-49;
        }
    }
}
// ������� ��� ������ �������
void PrintMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

// ������� ��� ���������� ������� �� ��������
void SortMatrix(int** matrix, int rows, int cols) {
    for (int j = 0; j < cols; j++) {
        for (int i = 0; i < rows - 1; i++) {
            for (int k = 0; k < rows - i - 1; k++) {
                if (matrix[k][j] < matrix[k + 1][j]) {
                    // ����� ���������
                    int temp = matrix[k][j];
                    matrix[k][j] = matrix[k + 1][j];
                    matrix[k + 1][j] = temp;
                }
            }
        }
    }
}

// ������� ��� ����� ������
void InpString(char* str, int max_length) {
    printf("������� ������ (�������� %d ��������): ", max_length - 1);
    fgets(str, max_length, stdin);
    str[strcspn(str, "\n")] = '\0';
}

void PrintString(const char* str) {
    printf("��������� ������: %s\n", str);
}

// ������� ��� �������� ���������� ���� � ������
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
        printf("������� ������ �������: ");
        scanf_s("%d", &arrlength);

        if (arrlength <= 0) {
            printf("������ ������� ������ ���� ������ ����.\n");
        }
    } while (arrlength <= 0);

    // ��������� ������ ��� �������
    int* array = (int*)malloc(arrlength * sizeof(int));
    GenArr(array, arrlength);

    printf("��������������� ������: ");
    PrintArr(array, arrlength);

    FindFibonacci(array, arrlength);

    int matrows, matcols;
    do {
        printf("������� ���������� ����� �������: ");
        scanf_s("%d", &matrows);

        if (matrows <= 0) {
            printf("���������� ����� ������ ���� ������ ����.\n");
        }
        getchar(); // ������� �������� ������
    } while (matrows <= 0);

    do {
        printf("������� ���������� �������� �������: ");
        scanf_s("%d", &matcols);

        if (matcols <= 0) {
            printf("���������� �������� ������ ���� ������ ����.\n");
        }
        getchar(); // ������� �������� ������
    } while (matcols <= 0);

    // ��������� ������ ��� �������
    int** matrix;
    GenMatrix(&matrix, matrows, matcols);

    printf("��������������� �������:\n");
    PrintMatrix(matrix, matrows, matcols);
    SortMatrix(matrix, matrows, matcols); // ���������� �������
    printf("��������������� �������:\n");
    PrintMatrix(matrix, matrows, matcols);

    // ���� � ����� ������
    char inputString[100]; // ������������ ����� ������ 100 ��������
    InpString(inputString, sizeof(inputString));
    PrintString(inputString);
    // ������� ���������� ���� � ������
    int wordCount = Words(inputString);
    printf("���������� ���� � ������: %d\n", wordCount);

    // ������������ ������ ����� ����������� ���������
    free(array);
    return 0;
}