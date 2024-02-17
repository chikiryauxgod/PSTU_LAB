#include <iostream>
using namespace std;

int q(int arr[], int size)
{
	if (size == 0)
	{
		return 0;
	}

	return 1 + q(arr + 1, size - 1);
}


int main()
{

	int arr[] = { 3, 1, 4, 50, 113 };
	int size = sizeof(arr) / sizeof(arr[0]);
	int quantity = q(arr, size);
	cout << "Sum of array elements are: " << quantity << endl;
	return 0;
}