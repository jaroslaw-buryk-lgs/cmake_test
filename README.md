# Calculator Project

A simple calculator application built with C++ and CMake, demonstrating proper project structure with separated concerns.

## Project Structure

```
.
├── lib/                      # Business Logic Library
│   ├── include/
│   │   └── calculator.h     # Calculator interface
│   ├── src/
│   │   └── calculator.cpp   # Calculator implementation
│   └── CMakeLists.txt       # Library build configuration
├── app/                      # Command-line UI Application
│   ├── main.cpp             # Main application entry point
│   └── CMakeLists.txt       # Application build configuration
├── tests/                    # Unit Tests
│   ├── test_calculator.cpp  # Calculator tests
│   └── CMakeLists.txt       # Tests build configuration
└── CMakeLists.txt           # Root build configuration
```

## Components

1. **Business Logic Library** (`lib/`): Contains the core calculator functionality with basic arithmetic operations (add, subtract, multiply, divide) and trigonometric functions (sin, cos, tan).

2. **Command-line UI** (`app/`): An interactive command-line interface that allows users to perform calculator operations.

3. **Unit Tests** (`tests/`): Comprehensive tests for the calculator business logic.

## Building the Project

```bash
mkdir build
cd build
cmake ..
make
```

## Running the Application

After building, run the calculator application:

```bash
./app/calculator_app
```

## Running Tests

After building, run the unit tests:

```bash
./tests/calculator_tests
```

Or use CTest:

```bash
ctest
```

## Features

- Addition, subtraction, multiplication, and division operations
- Trigonometric functions: sin, cos, and tan (input in radians)
- Error handling for division by zero
- Error handling for undefined trigonometric values (e.g., tan(π/2))
- Interactive command-line interface
- Comprehensive unit tests for business logic