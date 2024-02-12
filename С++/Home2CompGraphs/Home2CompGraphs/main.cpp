#include <iostream>
#include <vector>


using namespace std;

struct Point {
    double x, y;
};


double areaCalculate(const vector<Point>& points) {
    double area = 0.0;
    for (int i = 0; i < points.size(); ++i) {
        Point current = points[i];
        Point next = points[(i + 1) % points.size()];
        area += (current.x * next.y - next.x * current.y);
    }
    return fabs(area) / 2.0;
}

int main() {
    setlocale(LC_ALL, "ru");
    vector<Point> points = {
        {0.0, 0.0},
        {4.0, 0.0},
        {4.0, 3.0},
        {0.0, 3.0}
    };

    double areaResult = areaCalculate(points);
    cout << "Площадь четырехугольника методом шнурка: " << areaResult << endl;

    return 0;
}
