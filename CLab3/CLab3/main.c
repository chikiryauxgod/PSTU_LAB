#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
// Вариант 16
int main() {
    setlocale(LC_ALL, "ru");
    int n, K, M;

    printf("Введите количество элементов массива: ");

    if (scanf_s("%d", &n) != 1 || n <= 0) {
        printf("Введено некорректное количество элементов.\n");
        return 1;
    }
    // Выделение памяти для массива
    int* arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Ошибка выделения памяти\n");
        return 1;
    }

    srand(time(NULL));
    // Генерация случайных чисел
    printf("Исходный массив: ");
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100 - 50;
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Удаление нечетных элементов
    printf("Массив после удаления нечетных элементов: ");
    int newSize = 0;
    // Вывод массива и оптимизация места 
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

    printf("\nВведите элемент K: ");
    if (scanf_s("%d", &K) != 1) {
        printf("Некорректный ввод для K\n");
        free(arr);
        return 1;
    }

    // Добавление элемента K в начало массива
    for (int i = n; i > 0; i--) {
        arr[i] = arr[i - 1];
    }
    arr[0] = K;
    n++;

    printf("Массив после добавления элемента K: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\nВведите количество позиций для сдвига M: ");
    if (scanf_s("%d", &M) != 1) {
        printf("Некорректный ввод для M\n");
        free(arr);
        return 1;
    }

    // Выполнение циклического сдвига на M элементов вправо
    for (int i = 0; i < M; i++) {
        int lastElement = arr[n - 1]; // Сохраняем последний элемент
        for (int j = n - 1; j > 0; j--) {
            arr[j] = arr[j - 1]; // Сдвигаем элементы вправо
        }
        arr[0] = lastElement; // Перемещаем последний элемент на начало
    }

    printf("Массив после циклического сдвига на %d элементов вправо: ", M);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    // Вычисление среднего арифметического
    double average = 0.0;
    for (int i = 0; i < n; i++) {
        average += arr[i];
    }
    average /= n;

    printf("\nСреднее арифметическое элементов: %.2f\n", average);

    // Поиск элемента, равного среднему арифметическому
    int found = 0; // Флаг, указывающий, найден ли элемент
    for (int i = 0; i < n; i++) {
        if (arr[i] == average) {
            printf("Элемент, равный среднему арифметическому элементов, найден: %d\n", arr[i]);
            found = 1;
            break; // Мы нашли элемент, выходим из цикла
        }
    }

    if (!found) {
        printf("Элемент, равный среднему арифметическому элементов, не найден.\n");
    }

    // Сортировка простым обменом (пузырьковая сортировка) по возрастанию
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Обмен элементов, если необходимо
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    printf("Массив после сортировки по возрастанию: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    for (int i = 0; i < n; i++) {
        if (arr[i] == average) {
            printf("\nЭлемент, равный среднему арифметическому элементов, найден: %d\n", arr[i]);
            found = 1;
            break; 
        }
    }

    if (!found) {
        printf("\nЭлемент, равный среднему арифметическому элементов, не найден.\n");
    }

    free(arr);
    return 0;
}
