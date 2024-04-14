#include <iostream>
#include <vector>
using namespace std;

vector<int> quickSort(vector<int> s)
{
    if (s.size() < 2)
    {
        return s;
    }

    vector<int> leftArray;
    vector<int> rightArray;

    int pivotIndex = (s.size() - 1) / 2; 
    for (int i = 0; i < s.size(); i++)
    {
        if (pivotIndex == i)  
        {
            continue;
        }
        int currentEl = s[i];
        if (currentEl >= s[pivotIndex])
        {
            rightArray.push_back(currentEl); 
        }
        else
        {
            leftArray.push_back(currentEl); 
        }
    }

    leftArray = quickSort(leftArray);
    rightArray = quickSort(rightArray);
    leftArray.push_back(s[pivotIndex]); 
    leftArray.insert(leftArray.end(), rightArray.begin(), rightArray.end()); 
    return leftArray; 
}

int main()
{
    vector<int> arr = { 1, 3, 33, 2, 1, 45, 51, 0, 12 };

    cout << "Sorted array: ";
    
    vector<int> sortedArr = quickSort(arr);
    for (int i = 0; i < sortedArr.size(); ++i)
    {
        cout << sortedArr[i] << " ";
    }
    cout << endl;

    return 0;
}
