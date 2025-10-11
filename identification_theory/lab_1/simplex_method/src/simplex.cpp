#include "simplex.hpp"
#include <algorithm>
#include <iostream>

int Simplex::iteration = 0;

Simplex::Simplex(const Config& cfg) : config(cfg) {}

void Simplex::AddVertex(const Vertex& v) {
    vertices.push_back(v);
}

void Simplex::Print() const {
    std::cout << "Iteration: " << iteration << "\n";
    for (const auto & v : vertices) {
        std::cout << "Vertex " << v.index << " | F = " << v.f << " | dB = ";
        v.dB.Print();
    }
}

void Simplex::ReplaceWorst(const Vertex & new_vertex) {
    Sort();
    vertices.back() = new_vertex;
}

void Simplex::Sort() {
	std::sort(vertices.begin(), vertices.end(),
		[](const Vertex & a, const Vertex & b) { return a.f < b.f; });
}
 
Vertex & Simplex::Worst() {
    Sort();
    return vertices.back();
}

Vector Simplex::GravityCenter() const {
    int m = vertices[0].dB.size();
    Vector C = Vector::Zero(m);
    for (int i = 0; i < vertices.size() - 1; ++i) {
        C = C + vertices[i].dB;
    }
    return C / (vertices.size() - 1);
}

const std::vector<Vertex>& Simplex::GetVertices() const {
    return vertices;
}

void Simplex::InitializeVertices(const Model & model, double a) {
    int m = model.ParameterCount();   
    vertices.clear();
    vertices.reserve(m + 1);


    Vector zero = Vector::Zero(m);
    vertices.emplace_back(0, zero, model.ComputeF(zero));

    double Pi  = (a / (m * 1.414)) * (std::sqrt(m + 1) - 1);
    double Pi1 = (a / (m * 1.414)) * (std::sqrt(m + 1) - 1 + m);

    for (int i = 0; i < m; ++i) {
        Vector dB = Vector::Zero(m);
        dB[i] = Pi1;
        for (int j = 0; j < m; ++j) {
            if (j != i) dB[j] = Pi;
        }

        double F = model.ComputeF(dB);
        vertices.emplace_back(i + 1, dB, F);
    }

    Sort();
}

Vertex Simplex::GetBest() const {
    std::vector<Vertex> tmp = vertices;
    std::sort(tmp.begin(), tmp.end(), [](const Vertex& a, const Vertex& b){ return a.f < b.f; });
    return tmp.front();
}


bool Simplex::Iterate(const Model & model) {
    iteration++;
    Sort(); // sort vertices

    Vertex& best = vertices.front();
    Vertex& worst = vertices.back();

    // 0) precision 
    if (best.f <= config.GetErrorFunctionLimit()) {
        return false;
    }

    // 0.5)  Fmax-Fmin difference is too small 
    double Fmin = vertices.front().f;
    double Fmax = vertices.back().f;
    if (std::abs(Fmax - Fmin) < eps_f_) {
        return false;
    }

    // 0.6) no progress
    if (best.f + 1e-300 < last_best_f_) { // (use +eps to avoid fp issues)
        last_best_f_ = best.f;
        no_improve_count_ = 0;
    } else {
        no_improve_count_++;
        if (no_improve_count_ >= max_no_improve_) {
            return false;
        }
    }

    Vector C = GravityCenter(); 
    int m = C.size();
    
    double alpha = config.GetAlpha();
    double beta  = config.GetAlpha();
    double gamma = config.GetGamma();

    Vector dB_star = (C * (1.0 + alpha)) - (worst.dB * alpha);
    double F_star = model.ComputeF(dB_star);
    if (!std::isfinite(F_star)) F_star = std::numeric_limits<double>::infinity();

    // a) Fl < F* < Fu
    if (best.f < F_star && F_star < worst.f) {
        worst.dB = dB_star;
        worst.f  = F_star;
    }
    // b) F* < Fl 
    else if (F_star < best.f) {
        Vector dB_exp = dB_star * beta + C * (1.0 - beta);
        double F_exp = model.ComputeF(dB_exp);
        if (!std::isfinite(F_exp)) F_exp = std::numeric_limits<double>::infinity();

        if (F_exp < best.f) {
            worst.dB = dB_exp;
            worst.f  = F_exp;
        } else {
            worst.dB = dB_star;
            worst.f  = F_star;
        }
    }
    // c) F* >= Fu или F* >= some other 
    else {
        Vector dB_cont = worst.dB * gamma + C * (1.0 - gamma);
        double F_cont = model.ComputeF(dB_cont);
        if (!std::isfinite(F_cont)) F_cont = std::numeric_limits<double>::infinity();

        if (F_cont < worst.f) {
            worst.dB = dB_cont;
            worst.f  = F_cont;
        } else {
            // shrink
            Vertex current_best = best; 
            for (size_t i = 1; i < vertices.size(); ++i) {
                vertices[i].dB = (vertices[i].dB + current_best.dB) / 2.0;
                vertices[i].f  = model.ComputeF(vertices[i].dB);
                if (!std::isfinite(vertices[i].f)) vertices[i].f = std::numeric_limits<double>::infinity();
            }
        }
    }

    // step < eps_dB_ - simplex converged
    double max_step = 0.0;
    for (const auto& v : vertices) {
        Vector diff = v.dB - best.dB;
        double norm = 0.0;
        for (int i = 0; i < diff.size(); ++i) norm += diff[i] * diff[i];
        max_step = std::max(max_step, std::sqrt(norm));
    }
    if (max_step < eps_dB_) return false;

    return true; 
}