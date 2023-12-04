#include "Time.h"
#include <iostream>
using namespace std;

int main() {
	Time a;
	Time b;
	Time c;
	cin >> a;
	cin >> b;
	++a;
	cout << a << endl;
	c = (a++) + b;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;

	return 0;
}