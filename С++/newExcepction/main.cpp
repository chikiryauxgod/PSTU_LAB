#include <iostream>
#include <string>
using namespace std;

class MyException : public exception
{
public:
	MyException(const char *msg, int dataState): exception(msg)
	{
		this->dataState = dataState;
	}
	int GetDataState()
	{
		return dataState;
	}
private:
	int dataState;
};

void function(int value)
{
	if (value < 0)
	{
		throw exception("The variable is weniger than a zero.");
	}
	if (value == 1)
	{
		throw MyException("We got a one.", value);
	}
	cout << "The variable: " << value << endl;
}

int main()
{
	try
	{
		function(-1);
	}
	catch (MyException &ex)
	{
		cout << "We caught: " << ex.what() << endl;
		cout << "The data is: " << ex.GetDataState() << endl;
	}
	catch (exception &ex)
	{
		cout << "We caught: " << ex.what() << endl;
	}
	
	return 0;
}