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
			cout << endl << "�������� ����������� ����� ����: " << endl;
			cout << "1. ������ ����� ��� �������� �������� ����� ������;" << endl;
			cout << "2. ��������� �������� �������� ������;" << endl;
			cout << "3. ���������  �������� �������� � �������������� ����������� ������;" << endl;
			cout << "4. �����." << endl;
			cout << "��� �����: ";
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
				cout << "�������� �����." << endl;
			}
		}
	}
	void SpeedTest(string& text) {
		cout << endl << "����� 5 ������ ��� ����� ����� ���������� � ������." << endl;
		this_thread::sleep_for(seconds(5));
		PrintText(text);

		cout << "���������!" << endl;
		auto start = high_resolution_clock::now();



		auto stop = high_resolution_clock::now();
		auto duration = duration_cast<seconds>(stop - start);
		cout << "����� ������: " << duration.count() << " ������" << endl;
	}

	void EnterText()
	{
		cout << "������� ����� ��� �������� �������� ����� ������: " << endl;
		getline(cin, text);
		PrintText(text);
	}

	void PrintText(string& text)
	{
		cout << "��� �����: " << endl;

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