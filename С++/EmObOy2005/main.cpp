#include <iostream>
#include <string>
using namespace std;

bool checkPassword(const string& password)
{
	bool hasDigit = false;
	bool hasUpper = false;
	bool hasLower = false;
	if (password.length() < 8)
	{
		return false;
	}

	for (char ch : password)
	{
		if (isdigit(ch))
		{
			hasDigit = true;
		}
		else if (isupper(ch))
		{
			hasUpper = true;
		}
		else if (islower(ch))
		{
			hasLower = true;
		}
	}

	if (!hasDigit || !hasLower || !hasUpper)
	{
		return false;
	}

	return true;
}

int main()
{
	string password;
	cin >> password;

	if (checkPassword(password))
	{
		cout << "YES" << endl;;
	}
	else
	{
		cout << "NO" << endl;;
	}

	return 0;
}