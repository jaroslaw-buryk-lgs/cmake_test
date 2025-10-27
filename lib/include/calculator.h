#ifndef CALCULATOR_H
#define CALCULATOR_H

class Calculator {
public:
    double add(double a, double b);
    double subtract(double a, double b);
    double multiply(double a, double b);
    double divide(double a, double b);
    
    // Trigonometric functions (input in radians)
    double sin(double x);
    double cos(double x);
    double tan(double x);
};

#endif // CALCULATOR_H
