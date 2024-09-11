#include <iostream>
#include <ctime>
using namespace std;

void createArray(const int &size, int* &array)
{
	array = new int[size];
	srand(time(0));
	for (int i = 0; i < size; ++i)
	{
		array[i] = rand() % 100;
	}
}

void findMaxMin(int* array, const int& size, int& max, int& min)
{
	min = max = 0;
	for (int i = 0; i < size; ++i)
	{
		if (array[i] > max)
		{
			max = array[i];
		}
		if (array[i] < min)
		{
			min = array[i];
		}

	}
}

void printArray(const int& size, int* array)
{
	for (int i = 0; i < size; ++i)
	{
		cout << array[i] << " " ;
		cout << endl;
	}

}

int main()
{		
	int* arr = nullptr;
	int size;
	cout << "How many elements you want to insert in array?" << endl;
	cin >> size;
	createArray(size, arr);
	int maximum(0), minimum(0);
	findMaxMin(arr, size, maximum, minimum);
	printArray(size, arr);
	cout << "The maximum value: " << maximum << endl;
	cout << "The minimum value: " << minimum;
	delete[] arr;
	return 0;
}