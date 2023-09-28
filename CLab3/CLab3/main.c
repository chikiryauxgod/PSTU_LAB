#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
// ������� 16
int main() {
    setlocale(LC_ALL, "ru");
    int n, K, M;

    printf("������� ���������� ��������� �������: ");

    if (scanf_s("%d", &n) != 1 || n <= 0) {
        printf("������� ������������ ���������� ���������.\n");
        return 1;
    }
    // ��������� ������ ��� �������
    int* arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("������ ��������� ������\n");
        return 1;
    }

    srand(time(NULL));
    // ��������� ��������� �����
    printf("�������� ������: ");
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100 - 50;
        printf("%d ", arr[i]);
    }
    printf("\n");

    // �������� �������� ���������
    printf("������ ����� �������� �������� ���������: ");
    int newSize = 0;
    // ����� ������� � ����������� ����� 
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            arr[newSize] = arr[i];
            newSize++;
        }
    }

    n = newSize;

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n������� ������� K: ");
    if (scanf_s("%d", &K) != 1) {
        printf("������������ ���� ��� K\n");
        free(arr);
        return 1;
    }

    // ���������� �������� K � ������ �������
    for (int i = n; i > 0; i--) {
        arr[i] = arr[i - 1];
    }
    arr[0] = K;
    n++;

    printf("������ ����� ���������� �������� K: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n������� ���������� ������� ��� ������ M: ");
    if (scanf_s("%d", &M) != 1) {
        printf("������������ ���� ��� M\n");
        free(arr);
        return 1;
    }

    // ���������� ������������ ������ �� M ��������� ������
    for (int i = 0; i < M; i++) {
        int lastElement = arr[n - 1]; // ��������� ��������� �������
        for (int j = n - 1; j > 0; j--) {
            arr[j] = arr[j - 1]; // �������� �������� ������
        }
        arr[0] = lastElement; // ���������� ��������� ������� �� ������
    }

    printf("������ ����� ������������ ������ �� %d ��������� ������: ", M);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    // ���������� �������� ���������������
    double average = 0.0;
    for (int i = 0; i < n; i++) {
        average += arr[i];
    }
    average /= n;

    printf("\n������� �������������� ���������: %.2f\n", average);

    // ����� ��������, ������� �������� ���������������
    int found = 0; // ����, �����������, ������ �� �������
    for (int i = 0; i < n; i++) {
        if (arr[i] == average) {
            printf("�������, ������ �������� ��������������� ���������, ������: %d\n", arr[i]);
            found = 1;
            break; // �� ����� �������, ������� �� �����
        }
    }

    if (!found) {
        printf("�������, ������ �������� ��������������� ���������, �� ������.\n");
    }

    // ���������� ������� ������� (����������� ����������) �� �����������
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // ����� ���������, ���� ����������
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    printf("������ ����� ���������� �� �����������: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    for (int i = 0; i < n; i++) {
        if (arr[i] == average) {
            printf("\n�������, ������ �������� ��������������� ���������, ������: %d\n", arr[i]);
            found = 1;
            break; 
        }
    }

    if (!found) {
        printf("\n�������, ������ �������� ��������������� ���������, �� ������.\n");
    }

    free(arr);
    return 0;
}