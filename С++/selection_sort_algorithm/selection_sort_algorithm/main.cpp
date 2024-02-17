#include <iostream>
#include <vector>
using namespace std;

template <typename T>
int find_smallest(const vector<T>& arr)
{
	T smallest = arr[0];
	int smallest_ind = 0;
	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i] < smallest)
		{
			smallest = arr[i];
			smallest_ind = i;
		}
	}
	return smallest_ind;
}

template <typename T>
vector <T> selection_sort(vector <T> arr) {
	vector <T> sorted;
	{
		while (!arr.empty())
		{
			int smallest_ind = find_smallest(arr);
			sorted.push_back(arr[smallest_ind]);
			arr.erase(arr.begin() + smallest_ind);

		}

	}
	return sorted;
}



 

int main()
{
	vector<double> arr = { 1, 1.2, 3, 0, -1.0, 0.5, 100, -99 };
	vector<double> sorted = selection_sort(arr);

	cout << "Sorted array: ";
	for (double num : sorted)
	{
		cout << num << " ";
	}
	cout << endl;
}
