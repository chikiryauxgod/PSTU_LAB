#include <iostream>
#include <string>
#include <ctime>
using namespace std;

string Generate(int size)
{
    srand(time(0));
    string password;
    for (int i = 0; i < size; i++)
    {
        char randomChar = static_cast<char>(' ' + rand() % ('~' - ' ' + 1));
        password += randomChar;
    }
    return password;
}

int main()
{
    setlocale(LC_ALL, "ru");
    int size = 20;
    string password = Generate(size);
    cout << "—генерированный пароль: " << password << endl;

    return 0;
}
