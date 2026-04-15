#include "input.h"
#include "operation.h"

#include <iostream>
#include <limits>


int Input::read_input(double &num1, Op_type &op_type, double &num2)
{
    std::cout << "Enter the first number(or 'q' to quit): ";
    if (Input::read_double(num1) == -1) {
        return -1;
    }

    std::cout << "Enter the second number(or 'q' to quit): ";
    if (Input::read_double(num2) == -1) {
        return -1;
    }

    char op_char {};
    std::cout << "Select the operation(+ - * /) or 'q' to quit: ";
    if (Input::read_operation(op_char) == -1) {
        return -1;
    }
    op_type = Operation::map_char_to_op(op_char);

    return 0;
}


int Input::read_double(double &num)
{
    // return -1 if user types 'q' else 0

    while (true) {
        if (std::cin >> num) {
            // we're sure that the first few characters are
            // definitely valid number.

            if (!stream_is_empty()) {
                // if stream still consists of some
                // characters, then its an error
                std::cin.clear();
                Input::ignore_line();
                std::cerr << "Enter a valid number: ";
                continue;
            }
            return 0;
        }
    }
}


int Input::read_operation(char &op_char)
{

}


bool Input::stream_is_empty()
{
    return (std::cin.eof() || std::cin.peek() == '\n');
}


void Input::ignore_line()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
