#include <iostream>
using namespace std;

void selectSort(int(&arr)[6], int len)
{
    // �������� �� ���� ��������� �������, ����� ����������
    for (int i = 0; i < len - 1; i++)
    {
        int indexMin = i; // �������������� ������ ������������ �������� �������� ����������
        // �������� �� ���������� ����� �������, ������� � ��������, ���������� �� �������
        for (int j = i + 1; j < len; j++)
        {
            // ���� ������� ������� �������, ��� ������� �����������, ��������� ������ ������������
            if (arr[j] < arr[indexMin])
            {
                indexMin = j;
            }
        }
        // ���� ��������� ����������� ������� �� ����� �������� �������, ������ �� �������
        if (indexMin != i)
        {
            int temp = arr[i]; // ��������� ���������� ��� ������ ��������
            arr[i] = arr[indexMin]; // ����� �������
            arr[indexMin] = temp; // ����� �������
        }
    }
}

int main()
{
    setlocale(LC_ALL, "ru");
    int array[] = { 1, 3, 50, 100, 300, 1000 }; // �������� ������
    int len = sizeof(array) / sizeof(int); // ��������� ����� �������
    selectSort(array, len); // ��������� ������ �� �����������
    // ������� ��������������� ������
    for (int i = 0; i < len; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}
