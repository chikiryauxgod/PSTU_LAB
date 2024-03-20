#include <string>
#include <iostream>
using namespace std;

class Testing {
private:
	string orgStr;
	string modStr;

public:
	Testing (const string& original) : orgStr(original), modStr(original) {}

	void left()
	{
		if (modStr.size() > 0)
		{
			modStr.pop_back();
		}
	}

	void bspace()
	{
		if (modStr.size() > 0)
		{
			modStr.pop_back();
		}
	}

	void right()
	{
		if (modStr.size() > 0)
		{
			modStr.pop_back();
		}
	}

	void del()
	{
		if (modStr.size() > 0)
		{
			modStr.pop_back();
		}
	}

	bool check ()
	{
		return orgStr == modStr;
	}

};



int main() {
	string original, modified;
	cin >> original;
	cin >> modified;

	Testing checker(original);

	for (char ch : modified)
	{
		if (ch == '<')
		{
			checker.left();
		}
		else if (ch == ' ')
		{
			checker.bspace();
		}
		else if (ch == '>')
		{
			checker.del();
		}
	}

	if (checker.check())
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;
	}


	return 0;
}