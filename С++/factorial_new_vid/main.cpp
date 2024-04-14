#include <iostream>
using namespace std;

long long int factorial(int n)
{
	if (n == 0 || n == 1)
	{
		return 1;
	}

	return n * (factorial(n - 1));
}


int main()
{	
	cout << factorial(20) << endl;

	return 0;
}