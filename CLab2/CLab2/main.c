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

    // ������������� ����� for
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        if (x % k1 == 0 && x % k2 != 0)
            count_for++;
    }

    printf("���������� ��������� ���� ������������������, ������� ����� k1 � �� ������� ����� k2 (��������� for): %d\n", count_for);

    printf("������� �������� ������������������: \n");

    // ����������� � ������ ������������������ ��� ������������� ����� while
    rewind(stdin);

    // ������������� ����� while
    int i = 0;
    while (i < n) {
        scanf("%d", &x);
        if (x % k1 == 0 && x % k2 != 0)
            count_while++;
        i++;
    }

    printf("���������� ��������� ���� ������������������, ������� ����� k1 � �� ������� ����� k2 (��������� while): %d\n", count_while);

    printf("������� �������� ������������������: \n");

    // ����������� � ������ ������������������ ��� ������������� ����� do-while
    rewind(stdin);

    // ������������� ����� do-while
    i = 0;
    do {
        scanf("%d", &x);
        if (x % k1 == 0 && x % k2 != 0)
            count_do_while++;
        i++;
    } while (i < n);

   
    
    printf("���������� ��������� ���� ������������������, ������� ����� k1 � �� ������� ����� k2 (��������� do-while): %d\n", count_do_while);

    return 0;
}
