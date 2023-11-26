#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <locale.h>
// ������� 16
int main() {
    setlocale(LC_ALL, "ru");
    int x, k1, k2, n, count_for = 0, count_while = 0, count_do_while = 0;

    printf("������� ����� n: ");
    scanf("%d", &n);

    printf("������� ����� k1: ");
    scanf("%d", &k1);

    printf("������� ����� k2: ");
    scanf("%d", &k2);

    printf("������� �������� ������������������: \n");

    // ������� ��������� ������� k1 � �� ������� k2
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        if (x % k1 == 0 && x % k2 != 0)
            count_for++;
    }

    printf("���������� ��������� ���� ������������������, ������� ����� k1 � �� ������� ����� k2 (��������� for): %d\n", count_for);

    int sum = 0;
    int t;

    // ������� ����� ������ ���������

    while (1) {
        printf("������� ����� ����� (��� ���������� ������� 0): ");
        scanf("%d", &t);

        if (t == 0) {
            break; // ����� �� ����� ��� ����� 0
        }

        if (t % 2 == 0) {
            sum += t;
        }
    }

    printf("����� ������ ���������: %d\n", sum);

    int prev = 0;
    int cur = 1;
    int follow, Q;

    printf("������� ����� Q: ");
    scanf("%d", &Q);

    printf("����� ��������� �� %d:\n", Q);

    // ���������� ����� ���������

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
