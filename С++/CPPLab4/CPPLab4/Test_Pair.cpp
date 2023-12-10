#include "Pair.h"
#include <iostream>
using namespace std;



int main1() {
	Pair a;
	cin >> a; 
	cout << a; 
	Pair b(1, 35);
	a = b;
	cout << a;

	return 0;
}
