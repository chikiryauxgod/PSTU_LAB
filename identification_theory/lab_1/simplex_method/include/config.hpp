#pragma once

class Config {
public:
    Config(float alpha, float beta, float gamma, float error_function_limit ) : alpha_(alpha), beta_(beta),
        gamma_(gamma), error_function_limit_(error_function_limit) {}

    float GetAlpha(void) const {return alpha_;}
    float GetBeta(void) const {return beta_; }
    float GetGamma(void) const {return gamma_; }
    float GetErrorFunctionLimit() const { return error_function_limit_; }

private:
    const float alpha_; // Reflection factor
    const float beta_; // Stretch factor
    const float gamma_; // Compression factor
    const float error_function_limit_; 
};