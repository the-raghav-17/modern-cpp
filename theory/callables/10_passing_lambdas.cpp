#include <iostream>


template <typename T>
void foo(T fun, int a, int b)
{
    fun(a, b);
}



int main()
{
    foo([](int a, int b){ std::cout << a - b; }, 10 , 20);
}
