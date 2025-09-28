#pragma once
#include "vector.hpp"
#include <vector>
#include <cmath>

class Model {
public:
    Model(const std::vector<double> & x, const std::vector<double> & y, const std::vector<double> & B)
        : x_(x), y_(y), B_(B) {}

    double ErrorFunction(const Vector & dB) const;
    double ComputeF(const Vector & dB) const;

    int Dimension() const { return (int)B_.size(); }
    double CalculateError(const Vector & dB) const;
    int ParameterCount() const { return B_.size(); }

private:
    std::vector<double> x_;
    std::vector<double> y_;
    std::vector<double> B_;
};
