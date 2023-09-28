#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Функция для ввода множества с клавиатуры
vector<int> InpSet() {
    vector<int> s;
    int n, element;
    cout << "Введите количество элементов: ";
    cin >> n;

    cout << "Введите элементы множества через пробел: ";
    for (int i = 0; i < n; ++i) {
        cin >> element;
        s.push_back(element);
    }

    sort(s.begin(), s.end()); // Удаление дубликатов
    s.erase(unique(s.begin(), s.end()), s.end());

    return s;
}

// Функция для генерации случайного множества
vector<int> GenRandSet(int size, int min, int max) {
    vector<int> s;
    for (int i = 0; i < size; ++i) {
        int element = rand() % (max - min + 1) + min;
        s.push_back(element);
    }

    // Удаление дубликатов
    sort(s.begin(), s.end());
    s.erase(unique(s.begin(), s.end()), s.end());

    return s;
}

// Функция для вывода множества на экран
void PrSet(const vector<int>& s) {
    for (int element : s) {
        cout << element << " ";
    }
    cout << endl;
}

// Операция: Пересечение двух множеств
vector<int> Intersec(const vector<int>& A, const vector<int>& B) {
    vector<int> result;
    for (int element : A) {
        if (find(B.begin(), B.end(), element) != B.end()) {
            result.push_back(element);
        }
    }
    return result;
}

// Операция: Объединение двух множеств
vector<int> UnSet(const vector<int>& A, const vector<int>& B) {
    vector<int> result = A;
    for (int element : B) {
        if (find(result.begin(), result.end(), element) == result.end()) {
            result.push_back(element);
        }
    }
    return result;
}

// Операция: Разность двух множеств
vector<int> Diff(const vector<int>& A, const vector<int>& B) {
    vector<int> result = A;
    for (int element : B) {
        auto it = find(result.begin(), result.end(), element);
        if (it != result.end()) {
            result.erase(it);
        }
    }
    return result;
}

// Операция: Симметрическая разность двух множеств
vector<int> SymDiff(const vector<int>& A, const vector<int>& B) {
    vector<int> result;
    for (int element : A) {
        if (find(B.begin(), B.end(), element) == B.end()) {
            result.push_back(element);
        }
    }
    for (int element : B) {
        if (find(A.begin(), A.end(), element) == A.end()) {
            result.push_back(element);
        }
    }
    return result;
}

// Операция: Дополнение множества A до U
vector<int> Compl(const vector<int>& A, const vector<int>& U) {
    vector<int> result = U;
    for (int element : A) {
        auto it = find(result.begin(), result.end(), element);
        if (it != result.end()) {
            result.erase(it);
        }
    }
    return result;
}

int main() {
    setlocale(LC_ALL, "ru");
    srand(time(0)); // Инициализация генератора случайных чисел

    vector<int> U;
    vector<int> A, B, C, D, E;
    vector<vector<int>> AllSets = { A, B, C, D, E }; // Вектор всех множеств

    char choice;
    bool exit = false;

    while (!exit) {
        cout << "\nМеню:" << endl;
        cout << "1. Задать универсальное множество U" << endl;
        cout << "2. Ввести множества A, B, C, D, E" << endl;
        cout << "3. Выполнить операции над множествами" << endl;
        cout << "4. Проверить принадлежность элемента множеству" << endl;
        cout << "5. Проверить вхождение одного множества в другое" << endl;
        cout << "6. Сгенерировать случайное множество" << endl;
        cout << "7. Выйти" << endl;

        cin >> choice;

        switch (choice) {
        case '1':
            U = InpSet();
            break;
        case '2':
            for (int i = 0; i < 5; ++i) {
                cout << "Введите множество " << char('A' + i) << ":" << endl;
                AllSets[i] = InpSet();
            }
            break;
        case '3': {
            char operation;
            cout << "Выберите операцию (a, b, c, d, e): \n";
            cout << " a - Пересечение \n b - Объединение \n c - Разность \n d - Симметрическая разность \n e - Дополнение \n ";
            cin >> operation;

            vector<int> result;

            cout << "Выберите множество для левой части операции (A, B, C, D, E): ";
            char LSet;
            cin >> LSet;
            vector<int> L = AllSets[LSet - 'A'];

            cout << "Выберите множество для правой части операции (A, B, C, D, E): ";
            char RSet;
            cin >> RSet;
            vector<int> R = AllSets[RSet - 'A'];

            switch (operation) {
            case 'a':
                result = Intersec(L, R);
                break;
            case 'b':
                result = UnSet(L, R);
                break;
            case 'c':
                result = Diff(L, R);
                break;
            case 'd':
                result = SymDiff(L, R);
                break;
            case 'e':
                result = Compl(L, U);
                break;
            default:
                cout << "Неверная операция." << endl;
                break;
            }

            cout << "Результат операции: ";
            PrSet(result);
            break;
        }
        case '4': {
            int element;
            cout << "Введите элемент: ";
            cin >> element;
            for (int i = 0; i < 5; ++i) {
                if (find(AllSets[i].begin(), AllSets[i].end(), element) != AllSets[i].end()) {
                    cout << element << " принадлежит множеству " << char('A' + i) << endl;
                }
                else {
                    cout << element << " не принадлежит множеству " << char('A' + i) << endl;
                }
            }
            break;
        }
        case '5': {
            char FirstSet, SecondSet;
            cout << "Введите первое множество (A, B, C, D, E): ";
            cin >> FirstSet;
            cout << "Введите второе множество (A, B, C, D, E): ";
            cin >> SecondSet;

            vector<int> L = AllSets[FirstSet - 'A'];
            vector<int> R = AllSets[SecondSet - 'A'];

            bool IsSub = true;
            for (int element : L) {
                if (find(R.begin(), R.end(), element) == R.end()) {
                    IsSub = false;
                    break;
                }
            }
            if (IsSub) {
                cout << "Первое множество является подмножеством второго." << endl;
            }
            else {
                cout << "Первое множество не является подмножеством второго." << endl;
            }
            break;
        }
        case '6': {
            char RandSet;
            cout << "Выберите множество для генерации случайных чисел (A, B, C, D, E): ";
            cin >> RandSet;

            int size, min, max;
            cout << "Введите размер случайного множества: ";
            cin >> size;
            cout << "Введите минимальное значение элемента: ";
            cin >> min;
            cout << "Введите максимальное значение элемента: ";
            cin >> max;

            vector<int> GenSet = GenRandSet(size, min, max);
            AllSets[RandSet - 'A'] = GenSet;

            cout << "Сгенерированное случайное множество " << RandSet << ": ";
            PrSet(GenSet);
            break;
        }
        case '7':
            exit = true; // Выход из цикла
            break;
        default:
            cout << "Неверный выбор. Пожалуйста, выберите снова." << endl;
            break;
        }
    }

    return 0;
}
