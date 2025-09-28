#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <limits>

using Vector = std::vector<double>;

void PrintVector(const Vector & v) {
    std::cout << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        std::cout << std::fixed << std::setprecision(6) << v[i];
        if (i + 1 < v.size()) std::cout << ", ";
    }
    std::cout << "]";
}

double ErrorFunction(const Vector & x_, const Vector & y_,
                     double b1, double b2) {
    const size_t n = x_.size();
    double F = 0.0;
    for (size_t i = 0; i < n; ++i) {
        if (b2 * x_[i] <= 0) return std::numeric_limits<double>::infinity();
        double y_pred = b1 * std::log(b2 * x_[i]);
        double diff = y_[i] - y_pred;
        F += diff * diff;
    }
    return F;
}

double ErrorFunction(const Vector & x_, const Vector & y_, const Vector & params) {
    if (params.size() != 2) {
        throw std::runtime_error("params size must be 2!");
    } 
    return ErrorFunction(x_, y_, params[0], params[1]);
}

Vector DirectSearch(const Vector & x_, const Vector & y_,
        Vector b_j, double delb1, double error_function_limit, int max_iters = 10000)
{
    double F_error = ErrorFunction(x_, y_, b_j);
    std::cout << "Initial error: " << std::fixed << std::setprecision(6) << F_error << "\n";
    int count = 0;

    const size_t param_count = b_j.size();
    if (param_count == 0) return b_j;

    while (true) {
        ++count;
        bool found = false;
        double best_F_error = F_error;
        Vector best_b_j = b_j;

        for (size_t i = 0; i < param_count; ++i) {
            for (double delta : { delb1, -delb1, 0.0 }) {
                Vector new_b_j = b_j;
                new_b_j[i] += delta;
                if (new_b_j[1] <= 0) continue;

                double new_F_error = ErrorFunction(x_, y_, new_b_j);

                if (new_F_error < best_F_error) {
                    best_F_error = new_F_error;
                    best_b_j = new_b_j;
                    found = true;
                }
            }
        }

        if (found) {
            b_j = best_b_j;
            F_error = best_F_error;
            std::cout << "Iteration " << count << ": Updated parameters: ";
            PrintVector(b_j);
            std::cout << ", Error: " << std::fixed << std::setprecision(6) << F_error << "\n";
        } else {
            std::cout << "Local minimum found after " << count << " iterations\n";
            break;
        }

        if (F_error < error_function_limit) {
            std::cout << "Desired error threshold reached after " << count << " iterations\n";
            break;
        }

        if (count >= max_iters) {
            std::cout << "Max iterations reached (" << max_iters << "), stopping.\n";
            break;
        }
    }
    return b_j;
}


int main() {
    Vector B = {2.0, 1.0};
    Vector x_ = {0.1, 0.9, 1.0, 2.0, 5.0, 6.0, 7.0, 10.0, 15.0, 16.0, 17.0};
    Vector y_ = {-4.767, -0.394, -0.185, 1.195, 3.018, 3.381, 3.688, 4.398, 5.205, 5.333, 5.454};

    double delb1 = 0.1;
    double error_function_limit = 0.001;

    std::cout << "Start Direct Search for y = b1*ln(b2*x)\n";
    Vector best_b = DirectSearch(x_, y_, B, delb1, error_function_limit, 10000);

    std::cout << "\nBest parameters found: ";
    PrintVector(best_b);
    std::cout << "\nFinal Error: " << std::fixed << std::setprecision(6)
              << ErrorFunction(x_, y_, best_b) << "\n";

    return 0;
}
