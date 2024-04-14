#include <iostream>
#include <string>
#include <chrono>
#include <thread>
using namespace std;
using namespace chrono;

class InputText {
public:
	void Menu()
	{
		while (true)
		{
			cout << endl << "Выберите необходимый пункт меню: " << endl;
			cout << "1. Ввести текст для проверки скорости вашей печати;" << endl;
			cout << "2. Выполнить проверку скорости печати;" << endl;
			cout << "3. Повторить  проверку скорости с использованием предыдущего текста;" << endl;
			cout << "4. Выход." << endl;
			cout << "Ваш пункт: ";
			cin >> num;
			cin.ignore();
			switch (num)
			{
			case 1:
				EnterText();
				break;
			case 2:
				SpeedTest(text);
				break;
			case 4:
				exit(0);
				break;
			default:
				cout << "Неверный пункт." << endl;
			}
		}
	}
	void SpeedTest(string& text) {
		cout << endl << "Через 5 секунд вам можно будет приступить к печати." << endl;
		this_thread::sleep_for(seconds(5));
		PrintText(text);

		cout << "Печатайте!" << endl;
		auto start = high_resolution_clock::now();

		

		auto stop = high_resolution_clock::now();
		auto duration = duration_cast<seconds>(stop - start);
		cout << "Время печати: " << duration.count() << " секунд" << endl;
	}

	void EnterText()
	{
		cout << "Введите текст для проверки скорости вашей печати: " << endl;
		getline(cin, text);
		PrintText(text);
	}

	void PrintText(string& text)
	{
		cout << "Ваш текст: " << endl;

		for (int i = 0; i < text.length(); i++) {
			cout << text[i];
			if (i % 50 == 0 && i != 0)
			{
				cout << endl;
			}
		}
	}

private:
	string text;
	int num;
};

int main() {
	setlocale(LC_ALL, "ru");
	InputText test;
	test.Menu();
	
	return 0;
}