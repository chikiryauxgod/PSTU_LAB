#define _CRT_SECURE_NO_WARNINGS // ����� �� ���� ������
#include <stdio.h>
#include <math.h>
#include <locale.h>
// ������� 16
int main() {
    setlocale(LC_ALL, "ru");
    int res;
    double x; // ���� �
    printf("������� �������� x: ");
    scanf("%lf", &x);

    // ��������� �������� ���������
    double result = sqrt(sin(x) + fabs(x * x + x));

    printf("��������� ����������: %lf\n", result);

    double x1, y1;
    printf("������� �������� x1: ");
    scanf("%lf", &x1);
    printf("������� �������� y1: ");
    scanf("%lf", &y1);

    // ���������, ����������� �� ����� ������������ �������� �� ������������ ���������

    res = ((y1 >= 0 && y1 * y1 + x1 * x1 <= 1 && x1 >= -1) || (y1 <= 0 && y1 * y1 + x1 * x1 <= 1 && x1 <= 1)) || ((x1 >= 0 && y1 <= -0.2 * x1 + 1) || (x1 <= 0 && y1 >= -0.2 * x1 - 1));



    printf("��������� ����� � �������: %i\n", res);


    return 0;
}