#include <functional>
#include <iostream>


void foo1(int i, double d)
{
    std::cout << "i: " << i << '\n';
    std::cout << "d: " << d << '\n';
}


int main()
{
    auto bar = std::bind(foo1, 10, 3.14);
    bar();
}
