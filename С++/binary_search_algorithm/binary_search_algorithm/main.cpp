#include <iostream>
using namespace std;
// Бинарный поиск получает на вход отсортированный список элементов, если элемент, который мы ищем, присутствует, то алгоритм возвращает его позицию
// При бинарном поиске каждый раз отсекается половина элементов
// Работает только тогда, когда список отсортирован
int binarysearch(int array[], int element, int &len)
{
	int low = 0;
	int high = len;
	while (low <= high)
	{
		int mid = (low + high) / 2;
		int guess = array[mid];
		if (guess == element)
		{
			cout << "Элемент " << element << " найден на позиции " << mid << endl;
			return 0;
		}
		else if (guess > element)
		{
			high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
	}
	cout << "Элемент не найден" << endl;
	return 0;
}

int main()
{
	setlocale(LC_ALL, "ru");
	int array[] = { 2, 10, 23, 44, 55, 69, 100, 123, 256, 420, 1488 };
	int len = sizeof(array) / sizeof(int);

	binarysearch(array, 2, len);
	binarysearch(array, 26, len);
	binarysearch(array, 1488, len);

}