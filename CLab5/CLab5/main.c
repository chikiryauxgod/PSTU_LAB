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
    int n = *length; // �������������� n ������� ��������� ����� �������
    for (int i = 0; i < *length; i++) {
        if (arr[i] < 0) {
            n++; // ����������� n, ���� ������� �����������
        }
    }

    // ������� ����� ������, �������� �������
    int* newArr = (int*)malloc(n * sizeof(int));
    if (newArr == NULL) {
        fprintf(stderr, "������ ��������� ������.\n");
        exit(1);
    }

    int newI = 0;
    for (int i = 0; i < *length; i++) {
        if (arr[i] < 0) {
            newArr[newI++] = abs(arr[i]); // ���� ������� �����������, ��������� ��� ������
        }
        newArr[newI++] = arr[i];
    }

    free(arr); // ����������� ������ ������� �������
    *length = n; // ��������� �������� �����

    return newArr; // ���������� ����� ������
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
    int newCols = *cols / 2; // ��������� ����� ���������� ��������
    int** newMatrix = (int**)malloc(*rows * sizeof(int*));

    for (int i = 0; i < *rows; i++) {
        newMatrix[i] = (int*)malloc(newCols * sizeof(int));
        int newIndex = 0;

        for (int j = 0; j < *cols; j++) {
            if (j % 2 == 0) { // ��������� ������ �������� ������� (�������� � 1 �� 0)
                for (int k = 0; k < *rows; k++) {
                    newMatrix[k][newIndex] = matrix[k][j];
                }
                newIndex++;
            }
        }
    }

    for (int i = 0; i < *rows; i++) {
        free(matrix[i]); // ����������� ������ ������ �������
    }
    free(matrix);

    *cols = newCols; // ��������� �������� ����� ��������
    return newMatrix; // ���������� ����� �������
}

int main() {
    setlocale(LC_ALL, "ru");
    int arrlength;

    do {
        printf("������� ������ �������: ");
        scanf("%d", &arrlength);

        if (arrlength <= 0) {
            printf("������ ������� ������ ���� ������ ����.\n");
        }
    } while (arrlength <= 0);

    int* arr = (int*)malloc(arrlength * sizeof(int));

    if (arr == NULL) {
        fprintf(stderr, "������ ��������� ������.\n");
        return 1;
    }

    GenArr(arr, arrlength);
    printf("�������� ������: ");
    PrintArr(arr, arrlength);

    int* modedArr = NegativeModul(arr, &arrlength);
    printf("������ � ������������ ��������: ");
    PrintArr(modedArr, arrlength);
    free(modedArr);

    int matrows, matcols;

    do {
        printf("������� ���������� ����� �������: ");
        scanf("%d", &matrows);

        if (matrows <= 0) {
            printf("���������� ����� ������ ���� ������ ����.\n");
        }
    } while (matrows <= 0);

    do {
        printf("������� ���������� �������� �������: ");
        scanf("%d", &matcols);

        if (matcols <= 0) {
            printf("���������� �������� ������ ���� ������ ����.\n");
        }
    } while (matcols <= 0);

    int** matrix;
    GenMatrix(&matrix, matrows, matcols);
    printf("�������� �������:\n");
    PrintMatrix(matrix, matrows, matcols);

    int** modedMatrix = NoEven(matrix, &matrows, &matcols);
    printf("������� ��� ������ ��������:\n");
    PrintMatrix(modedMatrix, matrows, matcols);

    for (int i = 0; i < matrows; i++) {
        free(modedMatrix[i]);
    }

    free(modedMatrix);

    return 0;
}
