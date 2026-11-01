#include <type_traits>
#include <iostream>


void fun1()
{
    std::cout << "function 1\n";
}

int fun2()
{
    std::cout << "function 2\n";
    return 100;
}


int main()
{
    if (std::is_void<decltype(fun1())>::value) {
	std::cout << "fun1 is of type void\n";
    }

    if (std::is_void_v<decltype(fun1())>) {
	std::cout << "Condition is true\n";
    }

    if (std::is_void<decltype(fun2())>::value) {
	std::cout << "fun2 is of type void\n";
    }
}
