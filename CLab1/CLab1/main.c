#define _CRT_SECURE_NO_WARNINGS // Чтобы не было ошибок
#include <stdio.h>
#include <math.h>
#include <locale.h>
// Вариант 16
int main() {
    setlocale(LC_ALL, "ru");
    int res;
    double x; // Ввод х
    printf("Введите значение x: ");
    scanf("%lf", &x);

    // Вычисляем значение выражения
    double result = sqrt(sin(x) + fabs(x * x + x));

    printf("Результат вычисления: %lf\n", result);

    double x1, y1;
    printf("Введите значение x1: ");
    scanf("%lf", &x1);
    printf("Введите значение y1: ");
    scanf("%lf", &y1);

    // Проверяем, принадлежит ли точка определенным областям на координатной плоскости

    res = ((y1 >= 0 && y1 * y1 + x1 * x1 <= 1 && x1 >= -1) || (y1 <= 0 && y1 * y1 + x1 * x1 <= 1 && x1 <= 1)) || ((x1 >= 0 && y1 <= -0.2 * x1 + 1) || (x1 <= 0 && y1 >= -0.2 * x1 - 1));



    printf("Попадание точки в область: %i\n", res);


    return 0;
}