#pragma once

class Config {
public:
    Config(int alpha, int beta, int gamma, float error_function_limit ) : alpha_(alpha), beta_(beta),
        gamma_(gamma), error_function_limit_(error_function_limit) {}

    int GetAlpha(void) const {return alpha_;}
    int GetBeta(void) const {return beta_; }
    int GetGamma(void) const {return gamma_; }
    float GetErrorFunctionLimit() const { return error_function_limit_; }

private:
    const int alpha_; // Reflection factor
    const int beta_; // Stretch factor
    const int gamma_; // Compression factor
    const float error_function_limit_; 
};