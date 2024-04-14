#include <iostream>
using namespace std;


int sumElements(int arr[], int len)
{
	if (len == 0)
	{
		return 0;
	}

	if (len == 1)
	{
		return arr[0];
	}

	return arr[0] + sumElements(arr + 1, len - 1);


}




int main()
{
	int array[] = {1, 3, 12, 4, 5, -6, 12};
	int length = sizeof(array) / sizeof(int);
	cout << "Summary of array elements = " << sumElements(array, length) << endl;
	return 0;
}