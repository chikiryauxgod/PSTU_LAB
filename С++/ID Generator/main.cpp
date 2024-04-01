#include <iostream>
#include <string>
using namespace std;

class Human 
{

public:
	static int count;

	Human(string name, string surname, int age)
	{
		this->name = name;
		this->surname = surname;
		this->age = age;
		count++;
		id = count;
	}

	int GetId()
	{
		return id;
	}
			
private:
	string name;
	string surname;
	int age;
	int id;
};

int Human::count = 0;

int main()
{
	setlocale(LC_ALL, "ru");
	Human person1("Lev", "Semenov", 19);
	cout << person1.GetId() << endl;
	Human person2("Matvey", "Petrov", 20);
	cout << person2.GetId() << endl;
}