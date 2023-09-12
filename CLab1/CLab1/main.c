#define _CRT_SECURE_NO_WARNINGS // Чтобы не было ошибок
#include <stdio.h>
#include <math.h>
#include <locale.h>
// Вариант 16
int main() {
    setlocale(LC_ALL, "ru");

    double x; // Ввод х
    printf("Введите значение x: ");
    scanf("%lf", &x);

    // Вычисляем значение выражения
    double result = sqrt(sin(x) + fabs(x * x + x));

    if (result >= 0) { // Проверка корня на неотрицательность
        printf("Результат вычисления: %lf\n", result);
    }
    else {
        printf("Ошибка: Выражение под корнем отрицательное.\n");
    }

    double x1, y1; 
    printf("Введите значение x1: ");
    scanf("%lf", &x1);
    printf("Введите значение y1: ");
    scanf("%lf", &y1);

    // Проверяем, принадлежит ли точка определенным областям на координатной плоскости

    // Проверка для 2 и 4 четвертей
    if ((pow(x1, 2) + pow(y1, 2) <= 1) && ((y1 <= 1 && x1 >= -1) || (y1 <= -1 && x1 >= 1))) {
        printf("True. \n");
    }
    // Проверка 1 и 3 четвертей
    else if ((y1 >= 0 && x1 >= 0 && x1 <= 5 * (1 - y1)) || (y1 <= 0 && x1 >= 0 && x1 <= 1 && y1 >= -sqrt(1 - x1 * x1))) {
        printf("True. \n");
    }
    else { // Если точка не принадлежит закрашенным зонам 
        printf("False.\n"); 
    }

    return 0;
}
