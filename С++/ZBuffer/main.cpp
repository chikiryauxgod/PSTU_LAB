#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <iomanip>

using namespace std;

struct Point {
    double x, y, z;
    string color;
};

class Screen {
public:
    Screen() {
        zeroPoint = { 0, 0, 0, "0" };
        screenBuffer.resize(36 * 36, zeroPoint); 
    }

    vector<Point>& getScreenBuffer() {
        return screenBuffer;
    }

    void Figure1(vector<Point>& points, const vector<Point>& figure) {
        int size = static_cast<int>(sqrt(points.size()));

        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                int index = i * size + j;
                double tempX = j;
                double tempY = i;

                points[index].x = tempX;
                points[index].y = tempY;

                if (tempX >= 10 && tempX <= 30 && tempY >= 0 && tempY <= 25) {
                    points[index].color = figure[index % figure.size()].color;
                    points[index].z = (3 * tempY + 50) / 5;
                }
            }
        }
    }

    void Figure2(vector<Point>& points, const vector<Point>& figure) {
        int size = static_cast<int>(sqrt(points.size()));
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                int index = i * size + j;
                double tempX = j;
                double tempY = i;

                if (tempY - 1.5 * tempX  + 12.5 <= 0 && tempY - 10 > 0 && tempY + 3 * tempX - 100 <= 0) {
                    points[index].color = figure[index % figure.size()].color;
                    double tempZ = (260 - 6 * tempX + tempY) / 9;
                    if (tempZ > points[index].z) {
                        points[index].z = tempZ;
                    }
                }
            }
        }
    }

    void printScreen() {
        int size = static_cast<int>(sqrt(screenBuffer.size()));

        cout << setw(4) << " ";
        for (int i = 0; i < size; i++) {
            cout << setw(3) << i;
        }
        cout << "\n";

        cout << "   ";
        for (int i = 0; i < size; i++) {
            cout << "---";
        }
        cout << "\n";

        for (int i = size - 1; i >= 0; i--) {
            cout << setw(2) << i << " |";
            for (int j = 0; j < size; j++) {
                int index = i * size + j;
                string color = screenBuffer[index].color;
                if (color == "R") {
                    cout << "\033[31m" << setw(3) << color << "\033[0m";
                }
                else if (color == "G") {
                    cout << "\033[32m" << setw(3) << color << "\033[0m";
                }
                else {
                    cout << setw(3) << color;
                }
            }
            cout << "\n";
        }
    }

private:
    Point zeroPoint;
    vector<Point> screenBuffer;
};

int main() {
    vector<Point> triangleVertices = { {15, 10, 20, "R"}, {25, 25, 15, "R"}, {30, 10, 10, "R"} };
    vector<Point> squareVertices = { {10, 0, 10, "G"}, {10, 25, 25, "G"}, {30, 25, 25, "G"}, {30, 0, 10, "G"} };

    Screen view;

    vector<Point>& buffer = view.getScreenBuffer();
    view.Figure1(buffer, squareVertices);
    view.Figure2(buffer, triangleVertices);
    view.printScreen();

    return 0;
}
