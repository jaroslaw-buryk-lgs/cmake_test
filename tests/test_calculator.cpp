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

void test_sin() {
    Calculator calc;
    
    // Test sin(0) = 0
    double result = calc.sin(0.0);
    if (!almostEqual(result, 0.0)) {
        throw std::runtime_error("Sin test failed: sin(0) should equal 0");
    }
    
    // Test sin(π/2) = 1
    result = calc.sin(M_PI / 2.0);
    if (!almostEqual(result, 1.0)) {
        throw std::runtime_error("Sin test failed: sin(π/2) should equal 1");
    }
    
    // Test sin(π) ≈ 0
    result = calc.sin(M_PI);
    if (!almostEqual(result, 0.0)) {
        throw std::runtime_error("Sin test failed: sin(π) should equal 0");
    }
    
    std::cout << "[PASS] test_sin" << std::endl;
}

void test_cos() {
    Calculator calc;
    
    // Test cos(0) = 1
    double result = calc.cos(0.0);
    if (!almostEqual(result, 1.0)) {
        throw std::runtime_error("Cos test failed: cos(0) should equal 1");
    }
    
    // Test cos(π/2) ≈ 0
    result = calc.cos(M_PI / 2.0);
    if (!almostEqual(result, 0.0)) {
        throw std::runtime_error("Cos test failed: cos(π/2) should equal 0");
    }
    
    // Test cos(π) = -1
    result = calc.cos(M_PI);
    if (!almostEqual(result, -1.0)) {
        throw std::runtime_error("Cos test failed: cos(π) should equal -1");
    }
    
    std::cout << "[PASS] test_cos" << std::endl;
}

void test_tan() {
    Calculator calc;
    
    // Test tan(0) = 0
    double result = calc.tan(0.0);
    if (!almostEqual(result, 0.0)) {
        throw std::runtime_error("Tan test failed: tan(0) should equal 0");
    }
    
    // Test tan(π/4) ≈ 1
    result = calc.tan(M_PI / 4.0);
    if (!almostEqual(result, 1.0)) {
        throw std::runtime_error("Tan test failed: tan(π/4) should equal 1");
    }
    
    std::cout << "[PASS] test_tan" << std::endl;
}

void test_tan_undefined() {
    Calculator calc;
    bool exceptionThrown = false;
    try {
        // tan(π/2) should throw an exception (undefined)
        calc.tan(M_PI / 2.0);
    } catch (const std::invalid_argument& e) {
        exceptionThrown = true;
    }
    if (!exceptionThrown) {
        throw std::runtime_error("Tan undefined test failed: should throw exception for π/2");
    }
    std::cout << "[PASS] test_tan_undefined" << std::endl;
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
    
    try {
        test_sin();
        passed++;
    } catch (const std::exception& e) {
        std::cout << "[FAIL] test_sin: " << e.what() << std::endl;
        failed++;
    }
    
    try {
        test_cos();
        passed++;
    } catch (const std::exception& e) {
        std::cout << "[FAIL] test_cos: " << e.what() << std::endl;
        failed++;
    }
    
    try {
        test_tan();
        passed++;
    } catch (const std::exception& e) {
        std::cout << "[FAIL] test_tan: " << e.what() << std::endl;
        failed++;
    }
    
    try {
        test_tan_undefined();
        passed++;
    } catch (const std::exception& e) {
        std::cout << "[FAIL] test_tan_undefined: " << e.what() << std::endl;
        failed++;
    }
    
    std::cout << "============================" << std::endl;
    std::cout << "Tests passed: " << passed << std::endl;
    std::cout << "Tests failed: " << failed << std::endl;
    
    return (failed == 0) ? 0 : 1;
}
