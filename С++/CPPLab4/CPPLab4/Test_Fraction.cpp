#include <iostream>
#include "Pair.h"
#include "Fraction.h"

using namespace std;

void f1(Pair& p) {
    cout << "Original Pair: " << p;


    Pair copy = p; 
    cout << "Copy of Pair: " << copy;

    Pair another;
    another = p; 
    cout << "Assigned Pair: " << another;


    Pair compare1(10, 20);
    Pair compare2(5, 25);

    cout << "compare1 == compare2: " << (compare1 == compare2) << endl;
    cout << "compare1 < compare2: " << (compare1 < compare2) << endl;

    cout << "\n End of f1\n \n " << endl;
}

Fraction f2() {
    cout << "\n Start of f2\n \n " << endl;

    Fraction fraction(1, 2, 3);
    cout << "Original Fraction: " << fraction;

    Fraction copy = fraction; 
    cout << "Copy of Fraction: " << copy;

    Fraction another;
    another = fraction; 
    cout << "Assigned Fraction: " << another;


    Fraction compare1(1, 2, 3);
    Fraction compare2(1, 2, 4);

    cout << "compare1 == compare2: " << (compare1 == compare2) << endl;
    cout << "compare1 < compare2: " << (compare1 < compare2) << endl;

    return fraction;
  
}

int main() {
    Pair p(5, 10);
    f1(p);


    Fraction result = f2();
    cout << "Result Fraction from f2: " << result;
    cout << "\n End of f2\n \n " << endl;

    return 0;
}
