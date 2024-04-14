#include <iostream>
using namespace std;

void selectSort(int(&arr)[6], int len)
{
    // Проходим по всем элементам массива, кроме последнего
    for (int i = 0; i < len - 1; i++)
    {
        int indexMin = i; // Инициализируем индекс минимального элемента текущего подмассива
        // Проходим по оставшейся части массива, начиная с элемента, следующего за текущим
        for (int j = i + 1; j < len; j++)
        {
            // Если находим элемент меньший, чем текущий минимальный, обновляем индекс минимального
            if (arr[j] < arr[indexMin])
            {
                indexMin = j;
            }
        }
        // Если найденный минимальный элемент не равен текущему индексу, меняем их местами
        if (indexMin != i)
        {
            int temp = arr[i]; // Временная переменная для обмена значений
            arr[i] = arr[indexMin]; // Обмен местами
            arr[indexMin] = temp; // Обмен местами
        }
    }
}

int main()
{
    setlocale(LC_ALL, "ru");
    int array[] = { 1, 3, 50, 100, 300, 1000 }; // Исходный массив
    int len = sizeof(array) / sizeof(int); // Вычисляем длину массива
    selectSort(array, len); // Сортируем массив по возрастанию
    // Выводим отсортированный массив
    for (int i = 0; i < len; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}
