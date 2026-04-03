#include <iostream>


enum class Operation {add, subtract, multiply, divide};


class Input
{
public:
        int read_input(double &num1, double &num2, Operation &operation);
};

int Input::read_input(double &num1, double &num2, Operation &operation)
{
    std::cout << "Enter the first number: ";
    std::cin  >> num1;
    std::cout << "Enter the second number: ";
    std::cin  >> num2;

    char op_char {};
    std::cout << "Enter the operation: ";
    std::cin  >> op_char;

    switch (op_char) {
        case '+': operation = Operation::add; break;
        case '-': operation = Operation::subtract; break;
        case '*': operation = Operation::multiply; break;
        case '/': operation = Operation::divide; break;
    }

    return 0;
}


class Calculator
{
public:
        void start();

private:
        double num1 {};
        double num2 {};
        Operation operation {};

        void print_details();
};


void Calculator::print_details()
{
    char op_char {};

    switch (operation) {
        case Operation::add:      op_char = '+'; break;
        case Operation::subtract: op_char = '-'; break;
        case Operation::multiply: op_char = '*'; break;
        case Operation::divide:   op_char = '/'; break;
    }

    std::cout << num1 << op_char << num2 << '\n';
}

void Calculator::start()
{
    Input input{};

    while (input.read_input(num1, num2, operation) != -1) {
        // do the rest of the stuff
        // for now, print the operation and numbers
        this->print_details();
    }
}


int main()
{
    Calculator calculator{};
    calculator.start();

    return 0;
}
