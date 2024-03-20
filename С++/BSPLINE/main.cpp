#include <iostream>
#include <vector>
using namespace std;

struct Point {
    double x;
    double y;
};

vector<Point> Moving(const vector<Point>& newVec) {
    vector<Point> newPoints;

    for (size_t i = 0; i < newVec.size(); ++i) {
        double a0, a1, a2, a3;
        double b0, b1, b2, b3;
        
        int idx_prev = (i == 0) ? newVec.size() - 1 : i - 1;
        int idx_next = (i == newVec.size() - 1) ? 0 : i + 1;
        int idx_next_next = (i == newVec.size() - 2) ? 0 : (i == newVec.size() - 1) ? 1 : i + 1;

        for (float t = 0.0; t <= 1.0; t += 0.1) { 
            a0 = (newVec[idx_prev].x + 4 * newVec[i].x + newVec[idx_next].x) / 6.0;
            a1 = (newVec[idx_prev].x * (-1) + newVec[idx_next].x) / 2.0;
            a2 = (newVec[idx_prev].x - 2 * newVec[i].x + newVec[idx_next].x) / 2.0;
            a3 = (newVec[idx_prev].x * (-1) + 3 * newVec[i].x - 3 * newVec[idx_next].x + newVec[idx_next_next].x) / 6.0;

            b0 = (newVec[idx_prev].y + 4 * newVec[i].y + newVec[idx_next].y) / 6.0;
            b1 = (newVec[idx_prev].y * (-1) + newVec[idx_next].y) / 2.0;
            b2 = (newVec[idx_prev].y - 2 * newVec[i].y + newVec[idx_next].y) / 2.0;
            b3 = (newVec[idx_prev].y * (-1) + 3 * newVec[i].y - 3 * newVec[idx_next].y + newVec[idx_next_next].y) / 6.0;

            double ax = ((a3 * t + a2) * t + a1) * t + a0;
            double by = ((b3 * t + b2) * t + b1) * t + b0;
            newPoints.push_back({ax, by});
        }
    }

    return newPoints;
}

int main() {
    vector<Point> figure = {
        {3, 1},
        {5, 3},
        {7, 1},
        {6, 5},
        {8, 7},
        {6, 7},
        {5, 9},
        {4, 7},
        {2, 7},
        {4, 5}
    };

    vector<Point> newFigure = Moving(figure);

    int count = 0;
    for (const auto& point : newFigure) {
        if (count % 5 == 0 && count != 0) {
            cout << endl;
        }
        cout << "(" << point.x << ", " << point.y << ") ";
        count++;
    }
    cout << endl;

    return 0;
}
