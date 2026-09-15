#include <iostream>


bool foo(int a, int b)
{
    return a == b;
}


int main()
{
    bool (*foo_ptr)(int, int){ foo };
    std::cout << foo_ptr(5, 10) << '\n';

    // The above is `implicit` calling because
    // we're not using the dereference operator
    // for calling the function, and it makes total
    // sense as the name of function is also a
    // pointer in itself and using the () operator
    // we're invoking that function pointer

    // Explicit calling, using * operator
    std::cout << (*foo_ptr)(17, 17) << '\n';

    // Likewise, dereferencing a nullptr function
    // pointer leads to undefined behavior

    foo_ptr = nullptr;
    (*foo_ptr)(10, 20);    // <-- leads to UB
}
