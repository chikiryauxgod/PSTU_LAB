#include <iostream>
#include <vector>
#include <cstdlib>
#include "Time.h"
using namespace std;

typedef vector<Time> Vec;

Vec make_vector(int n) {
    Vec v;
    for (int i = 0; i < n; i++) {
        int minutes = rand() % 100;
        int seconds = rand() % 60;
        v.push_back(Time(minutes, seconds));
    }
    return v;
}

void print_vector(const Vec& v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << "\n";
    }
    cout << endl;
}

int average(const Vec& v) {
    int s = 0;
    for (int i = 0; i < v.size(); i++) {
        s += v[i].get_total_seconds();
    }
    int n = v.size();
    return s / n;
}

void add_vector(Vec& v, const Time& el, int pos) {
    v.insert(v.begin() + pos, el);
}

int find_max(const Vec& v) {
    int m = v[0].get_total_seconds();
    int index = 0;
    for (int i = 0; i < v.size(); i++) {
        if (m < v[i].get_total_seconds()) {
            m = v[i].get_total_seconds();
            index = i;
        }
    }
    return index;
}

int find_min(const Vec& v) {
    int m = v[0].get_total_seconds();
    int index = 0;
    for (int i = 0; i < v.size(); i++) {
        if (m > v[i].get_total_seconds()) {
            m = v[i].get_total_seconds();
            index = i;
        }
    }
    return index;
}

void division(Vec& v) {
    int min_index = find_min(v);
    for (int i = 0; i < v.size(); i++) {
        v[i] = v[i] / v[min_index].get_total_seconds();
    }
}

void remove_max(Vec& v) {
    int max_index = find_max(v);

    if (!v.empty() && max_index >= 0 && max_index < v.size()) {
        v.erase(v.begin() + max_index);
    }
}

int main() {
    try {
        Vec v;
        int n;
        cout << "Enter the size of the vector: ";
        cin >> n;
        v = make_vector(n);

        cout << "Generated vector: ";
        print_vector(v);

        int el = average(v);
        Time new_element(el / 60, el % 60); 
        cout << "Average: " << el << " seconds" << endl;

        cout << "Enter the position to add an element: ";
        int pos;
        cin >> pos;
        if (pos > v.size()) {
            print_vector(v);
        }
        else {
            add_vector(v, new_element, pos);
            cout << "Vector after adding the element: ";
            print_vector(v);
        }

        remove_max(v);
        cout << "Vector after removing the maximum element: ";
        print_vector(v);

        division(v);
        cout << "Vector after division: ";
        print_vector(v);
    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
