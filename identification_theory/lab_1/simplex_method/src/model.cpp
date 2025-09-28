#include "model.hpp"


double Model::ErrorFunction(const Vector& dB) const {
    double F = 0.0;
    int m = Dimension();
    int N = (int)x_.size();

    for (int i = 0; i < N; ++i) {
        double y_pred = 0.0;
        for (int k = 0; k < m; ++k) {
            y_pred += (B_[k] + dB[k]) * std::pow(x_[i], k);
        }
        double diff = y_pred - y_[i];
        F += diff * diff;
    }
    return F;
}

double Model::CalculateError(const Vector& dB) const { // linear function error 
    if ((int)dB.size() != (int)B_.size()) {
        throw std::runtime_error("dB size isn't fits number of model parameters.");
    }

    double F = 0.0;
    int n = y_.size();

    for (int i = 0; i < n; ++i) {
        double y_pred = 0.0;
        double x_pow = 1.0;

        for (int j = 0; j < (int)B_.size(); ++j) {
            y_pred += (B_[j] + dB[j]) * x_pow;
            x_pow *= x_[i];
        }

        double diff = y_pred - y_[i];
        F += diff * diff;
    }

    return F;
}

double Model::ComputeF(const Vector & dB) const {
    if (dB.size() != 2) {
        throw std::runtime_error("dB size must be 2 for this model!");
    }

    double b1 = B_[0] + dB[0];
    double b2 = B_[1] + dB[1];

    if (b2 <= 0) return std::numeric_limits<double>::infinity();

    double F = 0.0;
    for (size_t i = 0; i < x_.size(); ++i) {
        double arg = b2 * x_[i];
        if (arg <= 0) return std::numeric_limits<double>::infinity();
        double ym = b1 * std::log(arg);
        double diff = y_[i] - ym;
        F += diff * diff;
    }

    return F;
}
