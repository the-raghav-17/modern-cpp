#include <iostream>


int main()
{
    int x { 100 };
    int& ref1 { x };
    int& ref2 { ref1 };

    ref2 = 10;
    ref1 = 12;
    x    = 123213;

    std::cout << x << '\n' << ref1 << '\n' << ref2 << '\n';
}
