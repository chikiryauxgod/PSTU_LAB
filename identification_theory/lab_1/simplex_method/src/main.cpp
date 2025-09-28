#include "simplex.hpp"
#include "model.hpp"
#include "config.hpp"
#include <iostream>

int main() {
    Config cfg(1, 2, 0.5, 0.001);

    std::vector<double> B = {2.0, 1.0};         
    std::vector<double> x = {0.1, 0.9, 1.0, 2.0, 5.0, 6.0, 7.0, 10.0, 15.0, 16.0, 17.0};    
    std::vector<double> y = {-4.767, -0.394, -0.185, 1.195, 3.018, 3.381, 3.688, 4.398, 5.205, 5.333, 5.454}; 

    Model model(x, y, B);
    Simplex simplex(cfg);

    simplex.InitializeVertices(model, 1.0);
    simplex.Print();

    while (simplex.Iterate(model)) {
        simplex.Print();
    }

    Vertex best = simplex.GetBest();
    std::cout << "Algorithm end at iteration: " << Simplex::iteration << "\n";
    std::cout << "Best dB: ";
    best.dB.Print(); 
    std::cout << "Final parameters B + dB: [ ";
    for (int i = 0; i < best.dB.size(); ++i) {
        double val = B[i] + best.dB[i]; 
        std::cout << val << (i+1<best.dB.size() ? ", " : " ]\n");
    }
    std::cout << "Final F = " << best.f << std::endl;
    return 0;
}
