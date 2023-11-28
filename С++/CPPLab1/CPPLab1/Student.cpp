#include <iostream>
#include <string>
#include "Student.h"
using namespace std;

Student::Student(){

	fip = "";
	group = "";
	average = 0;
	
	cout << "Constuctor bez parametrov dlya object: " << this << endl;
}

Student::Student(string N, string K, float S){

	fip = N;
	group = K;
	average = S;

	cout << "Constuctor s parametrami dlya object: " << this << endl;
}

Student::Student(const Student &t){
	fip = t.fip;
	group = t.group;
	average = t.average;

	cout << "Consturctor copyrovania dlya object: " << this << endl;
}

Student::~Student(){
	cout << "Destructor dlya object: " <<  this << endl;
}

string Student::get_fip(){
	return fip;
}

string Student::get_group(){
	return group;
}

float Student::get_average(){
	return average;
}

void Student::set_fip(string N){
	fip = N;
}

void Student::set_group(string K){
	group = K;
}

void Student::set_average(float S){
	average = S;
}

void Student::show() {
	cout << "Name: " << fip << endl;
	cout << "Group: " << group << endl;
	cout << "Average: "<< average << endl;
}

