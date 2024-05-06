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
        Screen() 
        {
            zeroPoint = { 0, 0, 0, " " };
            screenBuffer.resize(64, zeroPoint); 
        }

        vector<Point>& getScreenBuffer() 
        {
            return screenBuffer;
        }

        void Figure1(vector<Point>& points, const vector<Point>& figure) 
        {
            int size = static_cast<int>(sqrt(points.size()));
            for (int i = 0; i < size; i++) 
            {
                for (int j = 0; j < size; j++) 
                {
                    int index = i * size + j;
                    double tempX = j * 5;
                    double tempY = i * 5;

                    points[index].x = tempX;
                    points[index].y = tempY;

                    if (tempX >= 10 && tempX <= 30 && tempY >= 0 && tempY <= 25) 
                    {
                        points[index].color = figure[index % figure.size()].color;
                        points[index].z = (50 + 3 * tempY) / 5;
                    }
                }
            }
        }

        void Figure2(vector<Point>& points, const vector<Point>& figure) 
        {
            int size = static_cast<int>(sqrt(points.size()));
            for (int i = 0; i < size; i++) 
            {
                for (int j = 0; j < size; j++) 
                {
                    int index = i * size + j;
                    double tempX = j * 5;
                    double tempY = i * 5;

                    if (tempX * 1.5 - 12.5 - tempY > 0 && tempY > 0 && 3 * tempX - 100 - tempY < 0) 
                    {

                        points[index].color = figure[index % figure.size()].color;
                        points[index].z = (260 + tempY - 6 * (tempX + 5)) / 9;
                    }
                }
            }
        }

        void printScreen() {
            int size = static_cast<int>(sqrt(screenBuffer.size()));

            cout << setw(6) << " ";
            for (int i = 0; i < size; i++) 
            {
                cout << setw(4) << i * 5; 
            }
            cout << "\n";

         
            cout << "     ";
            for (int i = 0; i < size; i++) 
            {
                cout << "----";
            }
            cout << "\n";

            for (int i = 0; i < size; i++) 
            {
                cout << setw(3) << i * 5 << " |"; 
                for (int j = 0; j < size; j++) 
                {
                    int index = i * size + j;
                    cout << setw(4) << screenBuffer[index].color;
                }
                cout << "\n";
            }
        }

    private:
        Point zeroPoint;
        vector<Point> screenBuffer;
    };

    int main() {
        vector<Point> triangleVertices = { {15, 10, 20, "R"}, {25, 25, 15, "R"}, {30, 10, 20, "R"} };
        vector<Point> squareVertices = { {10, 0, 10, "G"}, {10, 25, 25, "G"}, {30, 25, 25, "G"}, {30, 0, 10, "G"} };

        Screen view;

        vector<Point>& buffer = view.getScreenBuffer();
        view.Figure1(buffer, squareVertices);
        view.Figure2(buffer, triangleVertices);
        view.printScreen();

        return 0;
    }
