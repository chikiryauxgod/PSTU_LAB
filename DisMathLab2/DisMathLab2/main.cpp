#include <iostream>
#include <vector>
#include <sstream>
#include <ctime>
#include <cstdlib>

using namespace std;

template <typename T>
string ToString(const T& value) {
    ostringstream oss;
    oss << value;
    return oss.str();
}

void ManualTruthTable(int n, vector<vector<int>>& truthTable) {
    for (int i = 0; i < (1 << n); ++i) {
        vector<int> row;
        for (int j = 0; j < n; ++j) {
            int value;
            cout << "Введите значение для переменной " << (j + 1) << " (0 или 1): ";
            cin >> value;
            row.push_back(value);
        }
        truthTable.push_back(row);
    }
    cout << "Введенная таблица истинности:" << endl;
    for (const vector<int>& row : truthTable) {
        for (int value : row) {
            cout << value << " ";
        }
        cout << endl;
    }
}

void RandomTruthTable(int n, vector<vector<int>>& truthTable) {
    srand(static_cast<unsigned>(time(0)));
    cout << "Случайно сгенерированная таблица истинности:" << endl;
    for (int i = 0; i < (1 << n); ++i) {
        vector<int> row;
        for (int j = 0; j < n; ++j) {
            int value = rand() % 2;
            row.push_back(value);
            cout << value << " ";
        }
        truthTable.push_back(row);
        cout << endl;
    }
}

void GenSDNFandSKNF(const vector<vector<int>>& truthTable, int n) {
    vector<string> sdnf;
    vector<string> sknf;

    for (const vector<int>& row : truthTable) {
        if (row.back() == 1) {
            string sdnfTerm;
            string sknfTerm;
            for (int j = 0; j < n; ++j) {
                if (row[j] == 1) {
                    sdnfTerm += 'x' + ToString(j);
                    sknfTerm += "x'" + ToString(j);
                }
                else {
                    sdnfTerm += "!x" + ToString(j);
                    sknfTerm += "x" + ToString(j);
                }
                if (j < n - 1) {
                    sdnfTerm += " || ";
                    sknfTerm += " && ";
                }
            }
            sdnf.push_back("(" + sdnfTerm + ")");
            sknf.push_back("(" + sknfTerm + ")");
        }
    }

    cout << "\nСДНФ: ";
    for (size_t i = 0; i < sdnf.size(); ++i) {
        cout << sdnf[i];
        if (i < sdnf.size() - 1) {
            cout << " || ";
        }
    }

    cout << "\nСКНФ: ";
    for (size_t i = 0; i < sknf.size(); ++i) {
        cout << sknf[i];
        if (i < sknf.size() - 1) {
            cout << " && ";
        }
    }

    cout << endl;
}

int main() {
    setlocale(LC_ALL, "ru");
    int n;
    cout << "Введите количество переменных (n <= 5): ";
    cin >> n;

    if (n < 1 || n > 5) {
        cout << "Количество переменных должно быть от 1 до 5." << endl;
        return 1;
    }

    int choice;
    cout << "Выберите способ задания таблицы истинности (1 - вручную, 2 - случайно): ";
    cin >> choice;

    vector<vector<int>> truthTable;

    if (choice == 1) {
        ManualTruthTable(n, truthTable);
    }
    else if (choice == 2) {
        RandomTruthTable(n, truthTable);
    }
    else {
        cout << "Неверный выбор способа задания таблицы истинности." << endl;
        return 1;
    }

    GenSDNFandSKNF(truthTable, n);

    return 0;
}
