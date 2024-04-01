#include <iostream>
#include <string>
using namespace std;

class Human 
{

public:
	

	Human(string name, string surname, int age)
	{
		this->name = name;
		this->surname = surname;
		this->age = age;
		count++;
		id = count;
	}

	int GetId() const
	{
		return id;
	}
		
	static int GetCount()
	{
		return count;
	}
private:
	string name;
	string surname;
	int age;
	int id;
	static int count;
};

int Human::count = 0;

int main()
{
	setlocale(LC_ALL, "ru");
	Human person1("Lev", "Semenov", 19);
	cout << Human::GetCount() << endl;
	Human person2("Matvey", "Petrov", 20);
	cout << Human::GetCount() << endl;
	/*
	cout << person1.GetId() << endl;
	cout << person2.GetId() << endl;
	*/
}