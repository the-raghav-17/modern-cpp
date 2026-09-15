#include <functional>
#include <iostream>


bool foo(int x, int y)
{
    return x == y;
}


int main()
{
    // Just a better way of writing and declaring function pointers
    std::function<bool(int, int)> fxn_obj{ foo };
    std::cout << fxn_obj(5, 5) << '\n';
}
