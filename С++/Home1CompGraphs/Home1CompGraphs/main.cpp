#include <iostream>
#include <Windows.h>
using namespace std;

struct Point 
{
    double x, y, w;
};

Point subtract(Point a, Point b) 
{
    return { a.x - b.x, a.y - b.y, 1.0 };
}

Point add(Point a, Point b) 
{
    return { a.x + b.x, a.y + b.y, 1.0 };
}

Point multiply(Point a, double scalar)
{
    return { a.x * scalar, a.y * scalar, 1.0 };
}

Point midpoint(Point a, Point b) 
{
    return multiply(add(a, b), 0.5);
}

void print(Point p1, Point p2) 
{
    double A = p1.y - p2.y;
    double B = p2.x - p1.x;
    double C = p1.x * p2.y - p2.x * p1.y;

    cout << A << " * x + " << B << " * y + " << C << " = 0" << endl;
}

int main() 
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Point A = { 1, 2, 1 };
    Point B = { 4, 2, 1 };
    Point C = { 4, 5, 1 };

    Point M = midpoint(A, B);
    Point MS = subtract(M, C);
    cout << "Уравнение медианы: ";
    print(MS, { 0, 0, 1 });

    Point BA = subtract(B, A);
    Point BC = subtract(B, C);
    Point BP = midpoint(A, add(multiply(BA, BC.w / BA.w), A));
    Point CP = midpoint(B, add(multiply(BC, BA.w / BC.w), B));

    cout << "Уравнение первой биссектрисы: ";
    print(BP, C);
    cout << "Уравнение второй биссектрисы: ";
    print(CP, A);

    Point H = midpoint(A, multiply(subtract(B, C), subtract(A, C).x / subtract(B, C).x));
    cout << "Уравнение высоты: ";
    print(subtract(A, H), B);

    return 0;
}
