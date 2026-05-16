#include "input.h"
#include "operation.h"

#include <iostream>
#include <limits>


int Input::read_input(double &num1, Op_type &op_type, double &num2)
{
    std::cout << "Enter the first number(or 'q' to quit): ";
    if (read_double(num1) == -1) {
        return -1;
    }

    std::cout << "Enter the second number(or 'q' to quit): ";
    if (read_double(num2) == -1) {
        return -1;
    }

    char op_char {};
    std::cout << "Select the operation(+ - * /) or 'q' to quit: ";
    if (read_operation(op_char) == -1) {
        return -1;
    }
    op_type = Operation::map_char_to_op(op_char);

    return 0;
}


int Input::read_double(double &num) const
{
    // return -1 if user types 'q' else 0

    while (true) {
        if (std::cin >> num) {
            // we're sure that the first few characters are
            // definitely valid number.

            if (!stream_is_empty()) {
                // if stream still consists of some
                // characters, then its an error
                reset_cin();
                std::cerr << "Enter a valid number: ";
                continue;
            }
            return 0;
        }
        else {
            // some non-number character was typed
            // if its 'q' followed by newline then we
            // need to return -1, else error

            std::cin.clear();
            char ch {};
            std::cin >> ch;

            // user typed 'q' and hit return
            if (ch == 'q' && stream_is_empty()) {
                return -1;
            }

            // for rest of the case, its an error
            reset_cin();
            std::cout << "Enter a valid number: ";

        }
    }
}


int Input::read_operation(char &op_char) const
{
    while (true) {
        reset_cin();
        std::cin >> op_char;

        if (std::cin.peek() != '\n') {
            std::cerr << "Enter a valid choice: ";
            continue;
        }

        switch (op_char) {
            case '+': case '-': case '*': case '/':
                return 0;

            case 'q':    // typed 'q'
                return -1;

            default:    // typed invalid character
                std::cerr << "Enter a valid choice: ";
                continue;
        }
    }
}


bool Input::stream_is_empty() const
{
    return (std::cin.eof() || std::cin.peek() == '\n');
}


void Input::ignore_line() const
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}


void Input::reset_cin() const
{
    ignore_line();
    std::cin.clear();
}
