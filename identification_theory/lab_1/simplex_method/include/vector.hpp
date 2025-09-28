#pragma once
#include <vector>
#include <iostream>

class Vector {
public:
    std::vector<double> data;

    Vector(int size = 0, double val = 0.0);
    int size() const;

    double& operator[](int i);
    const double& operator[](int i) const;
    void Print() const;


    Vector operator+(const Vector& other) const;
    Vector operator-(const Vector& other) const;
    Vector operator*(double scalar) const;
    Vector operator/(double scalar) const;

    static Vector Zero(int m);
};
