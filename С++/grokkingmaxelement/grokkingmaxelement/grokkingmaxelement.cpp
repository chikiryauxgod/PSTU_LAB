#include <iostream>
using namespace std;

int max(int arr[], int size)
{
	int y = 0;
	for (int i = 0; i < size; i++)
	{
		
		if (arr[i] > y)
		{
			y = arr[i];
		}
	}
	return y;
}


int main()
{

	int arr[] = { 3, 1, 4, 50, 113 };
	int size = sizeof(arr) / sizeof(arr[0]);
	int maxEl = max(arr, size);
	cout << "Max element of array: " << maxEl << endl;
	return 0;
}