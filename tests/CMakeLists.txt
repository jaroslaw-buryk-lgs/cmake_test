add_executable(calculator_tests
    test_calculator.cpp
)

target_link_libraries(calculator_tests PRIVATE
    calculator_lib
)

enable_testing()
add_test(NAME CalculatorTests COMMAND calculator_tests)
