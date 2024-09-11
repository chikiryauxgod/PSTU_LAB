#include <iostream>
using namespace std;

void printValue(void* ptr, char type)
{
	switch (type)
	{
	case 'i':
		cout << *static_cast<int*>(ptr) << endl;
		break;
	case 'd':
		cout << *static_cast<double*>(ptr) << endl;
		break;
	case 'c':
		cout << *static_cast<char*>(ptr) << endl;
		break;
	default:
		cout << "The unknown data type." << endl;
	}
}

int main()
{
	int intValue = 52;
	double doubleValue = 3.14;
	char charValue = 'Z';

	printValue(&intValue, 'i');
	printValue(&doubleValue, 'd');
	printValue(&charValue, 'c');


	return 0;
}

