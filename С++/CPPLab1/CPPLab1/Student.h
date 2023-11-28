#include <iostream>
#include <string>
using namespace std;

class Student
{
	string fip;
	string group;
	float average;

	public: Student();
		Student(string, string, float);
		Student(const Student&);
		~Student();
		string get_fip();
		void set_fip(string); 
		string get_group();
		void set_group(string); 
		float get_average();
		void set_average(float); 
		void show();

};

