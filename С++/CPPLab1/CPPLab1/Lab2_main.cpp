#include "Student.h"
#include <string>
#include <iostream>
using namespace std;

Student make_student() {
	string s1;
	string s2;
	float f;
	cout << "Vvedite name: ";
	cin >> s1;
	cout << "Vvedite groupu: ";
	cin >> s1;
	cout << "Vvedite sredniy ball: ";
	cin >> f;

	Student t(s1, s2, f);
	return t;
}

void print_student(Student t) {
	t.show();
}

void main() {
	Student t1;
	t1.show();
	Student t2("Petrov Matvey Sergeevich", "IPR-22-1B", 3.1);
	t2.show();
	Student t3 = t2;
	t3.set_fip("Kuimov Egor Borisovich");
	t3.set_group("NO GROUP");
	t3.set_average(2.0);
	print_student(t3);
	t1 = make_student();
	t2.show();
}

