#define _CRT_SECURE_NO_WARNINGS // ����� �� ���� ������
#include <stdio.h>
#include <math.h>
#include <locale.h>
// ������� 16
int main() {
    setlocale(LC_ALL, "ru");

    double x; // ���� �
    printf("������� �������� x: ");
    scanf("%lf", &x);

    // ��������� �������� ���������
    double result = sqrt(sin(x) + fabs(x * x + x));

    if (result >= 0) { // �������� ����� �� �����������������
        printf("��������� ����������: %lf\n", result);
    }
    else {
        printf("������: ��������� ��� ������ �������������.\n");
    }

    double x1, y1; 
    printf("������� �������� x1: ");
    scanf("%lf", &x1);
    printf("������� �������� y1: ");
    scanf("%lf", &y1);

    // ���������, ����������� �� ����� ������������ �������� �� ������������ ���������

    // �������� ��� 2 � 4 ���������
    if ((pow(x1, 2) + pow(y1, 2) <= 1) && ((y1 <= 1 && x1 >= -1) || (y1 <= -1 && x1 >= 1))) {
        printf("True. \n");
    }
    // �������� 1 � 3 ���������
    else if ((y1 >= 0 && x1 >= 0 && x1 <= 5 * (1 - y1)) || (y1 <= 0 && x1 >= 0 && x1 <= 1 && y1 >= -sqrt(1 - x1 * x1))) {
        printf("True. \n");
    }
    else { // ���� ����� �� ����������� ����������� ����� 
        printf("False.\n"); 
    }

    return 0;
}
