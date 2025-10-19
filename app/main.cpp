#include "calculator.h"
#include <iostream>
#include <string>
#include <limits>

void printMenu() {
    std::cout << "\n=== Simple Calculator ===" << std::endl;
    std::cout << "1. Add" << std::endl;
    std::cout << "2. Subtract" << std::endl;
    std::cout << "3. Multiply" << std::endl;
    std::cout << "4. Divide" << std::endl;
    std::cout << "5. Exit" << std::endl;
    std::cout << "Choose an operation: ";
}

bool getNumbers(double& a, double& b) {
    std::cout << "Enter first number: ";
    if (!(std::cin >> a)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input!" << std::endl;
        return false;
    }
    
    std::cout << "Enter second number: ";
    if (!(std::cin >> b)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input!" << std::endl;
        return false;
    }
    
    return true;
}

int main() {
    Calculator calc;
    int choice;
    double num1, num2, result;
    
    std::cout << "Welcome to the Calculator Application!" << std::endl;
    
    while (true) {
        printMenu();
        
        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input! Please enter a number." << std::endl;
            continue;
        }
        
        if (choice == 5) {
            std::cout << "Goodbye!" << std::endl;
            break;
        }
        
        if (choice < 1 || choice > 4) {
            std::cout << "Invalid choice! Please select 1-5." << std::endl;
            continue;
        }
        
        if (!getNumbers(num1, num2)) {
            continue;
        }
        
        try {
            switch (choice) {
                case 1:
                    result = calc.add(num1, num2);
                    std::cout << "Result: " << num1 << " + " << num2 << " = " << result << std::endl;
                    break;
                case 2:
                    result = calc.subtract(num1, num2);
                    std::cout << "Result: " << num1 << " - " << num2 << " = " << result << std::endl;
                    break;
                case 3:
                    result = calc.multiply(num1, num2);
                    std::cout << "Result: " << num1 << " * " << num2 << " = " << result << std::endl;
                    break;
                case 4:
                    result = calc.divide(num1, num2);
                    std::cout << "Result: " << num1 << " / " << num2 << " = " << result << std::endl;
                    break;
            }
        } catch (const std::exception& e) {
            std::cout << "Error: " << e.what() << std::endl;
        }
    }
    
    return 0;
}
