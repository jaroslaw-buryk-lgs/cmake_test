cmake_minimum_required(VERSION 3.10)

project(CalculatorProject VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add subdirectories for each component
add_subdirectory(lib)
add_subdirectory(app)
add_subdirectory(tests)
