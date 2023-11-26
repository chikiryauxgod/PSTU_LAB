#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <locale.h>
// Вариант 16
int main() {
    setlocale(LC_ALL, "ru");
    int x, k1, k2, n, count_for = 0, count_while = 0, count_do_while = 0;

    printf("Введите число n: ");
    scanf("%d", &n);

    printf("Введите число k1: ");
    scanf("%d", &k1);

    printf("Введите число k2: ");
    scanf("%d", &k2);

    printf("Вводите элементы последовательности: \n");

    // Подсчет элементов кратных k1 и не кратных k2
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        if (x % k1 == 0 && x % k2 != 0)
            count_for++;
    }

    printf("Количество элементов этой последовательности, кратных числу k1 и не кратных числу k2 (используя for): %d\n", count_for);

    int sum = 0;
    int t;

    // Подсчет суммы четных элементов

    while (1) {
        printf("Введите целое число (для завершения введите 0): ");
        scanf("%d", &t);

        if (t == 0) {
            break; // Выход из цикла при вводе 0
        }

        if (t % 2 == 0) {
            sum += t;
        }
    }

    printf("Сумма четных элементов: %d\n", sum);

    int prev = 0;
    int cur = 1;
    int follow, Q;

    printf("Введите число Q: ");
    scanf("%d", &Q);

    printf("Числа Фибоначчи до %d:\n", Q);

    // Вычисление чисел Фибоначчи

    do {
        if (prev <= Q) {
            printf("%d ", prev);
        }
        follow = prev + cur;
        prev = cur;
        cur = follow;
    } while (prev <= Q);

    printf("\n");

    return 0;
}
