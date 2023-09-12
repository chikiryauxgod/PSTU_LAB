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

    // Использование цикла for
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        if (x % k1 == 0 && x % k2 != 0)
            count_for++;
    }

    printf("Количество элементов этой последовательности, кратных числу k1 и не кратных числу k2 (используя for): %d\n", count_for);

    printf("Вводите элементы последовательности: \n");

    // Возвращение к началу последовательности для использования цикла while
    rewind(stdin);

    // Использование цикла while
    int i = 0;
    while (i < n) {
        scanf("%d", &x);
        if (x % k1 == 0 && x % k2 != 0)
            count_while++;
        i++;
    }

    printf("Количество элементов этой последовательности, кратных числу k1 и не кратных числу k2 (используя while): %d\n", count_while);

    printf("Вводите элементы последовательности: \n");

    // Возвращение к началу последовательности для использования цикла do-while
    rewind(stdin);

    // Использование цикла do-while
    i = 0;
    do {
        scanf("%d", &x);
        if (x % k1 == 0 && x % k2 != 0)
            count_do_while++;
        i++;
    } while (i < n);

   
    
    printf("Количество элементов этой последовательности, кратных числу k1 и не кратных числу k2 (используя do-while): %d\n", count_do_while);

    return 0;
}
