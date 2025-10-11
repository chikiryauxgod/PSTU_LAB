#include "vector.hpp"

Vector::Vector(int size, double val) : data(size, val) {}

int Vector::size() const {
    return static_cast<int>(data.size());
}

double& Vector::operator[](int i) {
    return data[i];
}

const double& Vector::operator[](int i) const {
    return data[i];
}

Vector Vector::operator+(const Vector& other) const {
    Vector result(size());
    for (int i = 0; i < size(); ++i)
        result[i] = data[i] + other[i];
    return result;
}

Vector Vector::operator-(const Vector& other) const {
    Vector result(size());
    for (int i = 0; i < size(); ++i)
        result[i] = data[i] - other[i];
    return result;
}

Vector Vector::operator*(double scalar) const {
    Vector result(size());
    for (int i = 0; i < size(); ++i)
        result[i] = data[i] * scalar;
    return result;
}

Vector Vector::operator/(double scalar) const {
    Vector result(size());
    for (int i = 0; i < size(); ++i)
        result[i] = data[i] / scalar;
    return result;
}

Vector Vector::Zero(int m) {
    return Vector(m, 0.0);
}

void Vector::Print() const {
    std::cout << "[";
    for (int i = 0; i < size(); ++i) {
        std::cout << data[i];
        if (i < size() - 1) std::cout << ", ";
    }
    std::cout << "]\n";
}