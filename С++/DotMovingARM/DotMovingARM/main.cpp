#include <SFML/Graphics.hpp>
#include <cmath>

struct Point {
    double x;
    double y;
    double z;
};

// ������� ��� ��������� ����� �� �������
Point multiplyPointByMatrix(Point p, double matrix[3][3], double a, double k, double l, double n) {
    Point result;

    result.x = p.x * (cos(a) + k * sin(a) + n) + p.y * (-sin(a) + k * cos(a) + n) + p.z * (l * cos(a) + k * l * sin(a) + n);
    result.y = p.x * 0 + p.y * 0 + p.z * 0; // ������ ������ ������� �������� ����, ������� ��������� ��� y ����� �������
    result.z = p.x * 0 + p.y * 0 + p.z * 1; // ������ ������ ������� [0 0 1], ������� ��������� ��� z ����� ����� z

    return result;
}

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Window"); // �������� ���� �������� 800x600

    Point initialPoint = { 1, -1, 0 }; // ��������� �����
    double matrix[3][3] = { {cos(0.5) + 1 * sin(0.5), -sin(0.5) + 1 * cos(0.5), 0},
                           {-sin(0.5) + 1 * cos(0.5), -sin(0.5) + 1 * cos(0.5), 0},
                           {1 * cos(0.5) + 1 * 1 * sin(0.5), -sin(0.5) + 1 * cos(0.5), 1} }; // �������

    double a = 0.5; // ���� a
    double k = 1;   // k
    double l = 1;   // l
    double n = 0;   // n

    Point resultPoint = multiplyPointByMatrix(initialPoint, matrix, a, k, l, n);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear(sf::Color::White); // ������� ����

        // ����������� ����� �� ��������� xy
        sf::CircleShape point(5);
        point.setFillColor(sf::Color::Red);
        point.setPosition(resultPoint.x + 400, -resultPoint.y + 300); // ������������� ����� �� ������
        window.draw(point);

        window.display(); // ����������� ����� ������������� �� ������
    }

    return 0;
}
