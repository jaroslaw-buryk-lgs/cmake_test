#include "calculator.h"
#include <stdexcept>
#include <cmath>
#include <limits>

double Calculator::add(double a, double b) {
    return a + b;
}

double Calculator::subtract(double a, double b) {
    return a - b;
}

double Calculator::multiply(double a, double b) {
    return a * b;
}

double Calculator::divide(double a, double b) {
    if (b == 0.0) {
        throw std::invalid_argument("Division by zero");
    }
    return a / b;
}

double Calculator::sin(double x) {
    return std::sin(x);
}

double Calculator::cos(double x) {
    return std::cos(x);
}

double Calculator::tan(double x) {
    // Check if cos(x) is close to zero, which would make tan undefined
    // Using a reasonable tolerance for floating-point comparison
    double cosine = std::cos(x);
    if (std::abs(cosine) < 1e-15) {
        throw std::invalid_argument("Tangent is undefined (approaching infinity)");
    }
    return std::tan(x);
}
