#pragma once
#include "config.hpp"
#include "vector.hpp"
#include "model.hpp"
#include <vector>

struct Vertex {
    int index;
    Vector dB;
    double f;

    Vertex(int idx, const Vector & dB, double F)
        : index(idx), dB(dB), f(F) {}
};

class Simplex {
public:
    static int iteration;

    Simplex(const Config & cfg);
    void AddVertex(const Vertex & v);
    void Print() const;
    void ReplaceWorst(const Vertex & new_vertex);
    Vertex GetBest() const; 
    void Sort();
    Vertex & Worst();
    Vector GravityCenter() const;
    const std::vector<Vertex> & GetVertices() const;

    void InitializeVertices(const Model & model, double a);
    bool Iterate(const Model & model); 

private:
    const Config & config;
    std::vector<Vertex> vertices;
    int no_improve_count_ = 0;
    int max_no_improve_ = 10;
    double eps_f_ = 1e-8;
    double eps_dB_ = 1e-6;
    double last_best_f_ = std::numeric_limits<double>::infinity();
};
