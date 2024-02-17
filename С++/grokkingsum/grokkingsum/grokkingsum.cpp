#include <iostream>
using namespace std;

int sum(int arr[], int size)
{
	if (size == 0)
	{
		return 0;
	}

	return arr[0] + sum(arr + 1, size - 1);
}


int main()
{

	int arr[] = {3, 1, 4, 50, 113};
	int size = sizeof(arr) / sizeof(arr[0]);
	int summary =  sum(arr, size);
	cout << "Sum of array elements are: " << summary << endl;
	return 0;
}