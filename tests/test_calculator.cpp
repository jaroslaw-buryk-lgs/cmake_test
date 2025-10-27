#include "calculator.h"
#include <iostream>
#include <cmath>
#include <stdexcept>

bool almostEqual(double a, double b, double epsilon = 1e-9) {
    return std::abs(a - b) < epsilon;
}

void test_addition() {
    Calculator calc;
    double result = calc.add(2.0, 3.0);
    if (!almostEqual(result, 5.0)) {
        throw std::runtime_error("Addition test failed: 2 + 3 should equal 5");
    }
    std::cout << "[PASS] test_addition" << std::endl;
}

void test_subtraction() {
    Calculator calc;
    double result = calc.subtract(5.0, 3.0);
    if (!almostEqual(result, 2.0)) {
        throw std::runtime_error("Subtraction test failed: 5 - 3 should equal 2");
    }
    std::cout << "[PASS] test_subtraction" << std::endl;
}

void test_multiplication() {
    Calculator calc;
    double result = calc.multiply(4.0, 3.0);
    if (!almostEqual(result, 12.0)) {
        throw std::runtime_error("Multiplication test failed: 4 * 3 should equal 12");
    }
    std::cout << "[PASS] test_multiplication" << std::endl;
}

void test_division() {
    Calculator calc;
    double result = calc.divide(10.0, 2.0);
    if (!almostEqual(result, 5.0)) {
        throw std::runtime_error("Division test failed: 10 / 2 should equal 5");
    }
    std::cout << "[PASS] test_division" << std::endl;
}

void test_division_by_zero() {
    Calculator calc;
    bool exceptionThrown = false;
    try {
        calc.divide(10.0, 0.0);
    } catch (const std::invalid_argument& e) {
        exceptionThrown = true;
    }
    if (!exceptionThrown) {
        throw std::runtime_error("Division by zero test failed: should throw exception");
    }
    std::cout << "[PASS] test_division_by_zero" << std::endl;
}

void test_negative_numbers() {
    Calculator calc;
    double result = calc.add(-5.0, 3.0);
    if (!almostEqual(result, -2.0)) {
        throw std::runtime_error("Negative numbers test failed: -5 + 3 should equal -2");
    }
    std::cout << "[PASS] test_negative_numbers" << std::endl;
}

int main() {
    int passed = 0;
    int failed = 0;
    
    std::cout << "Running Calculator Tests..." << std::endl;
    std::cout << "============================" << std::endl;
    
    try {
        test_addition();
        passed++;
    } catch (const std::exception& e) {
        std::cout << "[FAIL] test_addition: " << e.what() << std::endl;
        failed++;
    }
    
    try {
        test_subtraction();
        passed++;
    } catch (const std::exception& e) {
        std::cout << "[FAIL] test_subtraction: " << e.what() << std::endl;
        failed++;
    }
    
    try {
        test_multiplication();
        passed++;
    } catch (const std::exception& e) {
        std::cout << "[FAIL] test_multiplication: " << e.what() << std::endl;
        failed++;
    }
    
    try {
        test_division();
        passed++;
    } catch (const std::exception& e) {
        std::cout << "[FAIL] test_division: " << e.what() << std::endl;
        failed++;
    }
    
    try {
        test_division_by_zero();
        passed++;
    } catch (const std::exception& e) {
        std::cout << "[FAIL] test_division_by_zero: " << e.what() << std::endl;
        failed++;
    }
    
    try {
        test_negative_numbers();
        passed++;
    } catch (const std::exception& e) {
        std::cout << "[FAIL] test_negative_numbers: " << e.what() << std::endl;
        failed++;
    }
    
    std::cout << "============================" << std::endl;
    std::cout << "Tests passed: " << passed << std::endl;
    std::cout << "Tests failed: " << failed << std::endl;
    
    return (failed == 0) ? 0 : 1;
}
