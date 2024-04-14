#include <iostream>
using namespace std;

int binarySearch(int value, int array[], int length)
{
    int lowIndex = 0;
    int highIndex = length - 1;

    while (lowIndex <= highIndex)
    {
        int midIndex = (lowIndex + highIndex) / 2;
        if (array[midIndex] == value)
        {
            cout << midIndex << " - ����� �������� �������� � �������." << endl;
            return 0;
        }
        if (array[midIndex] > value)
        {
            highIndex = midIndex - 1;
        }
        else
        {
            lowIndex = midIndex + 1;
        }
    }
    cout << "������� �� ������ � �������." << endl;
    return 0;
}

int main()
{
    setlocale(LC_ALL, "ru");
    int array[] = { 1, 3, 50, 100, 300, 1000 };
    int val;
    int length = sizeof(array) / sizeof(int); 
    cout << "������� ������� ��� ������: " << endl;
    cin >> val;
    binarySearch(val, array, length);

    return 0;
}
