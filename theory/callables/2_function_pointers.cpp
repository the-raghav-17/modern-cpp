#include <functional>


bool foo(int a, int b)
{
    return a == b;
}


bool goo(int x, int y)
{
    return x != y;
}


int main()
{
    // Function pointer syntax

    // ret-type (*function-ptr-name) (params-type);

    bool (*foo_ptr)(int, int){ &foo };
    foo_ptr = &goo;

    // Here 'foo_ptr' is the name of the function ptr
    // This pointer points to a function, whose return
    // type is bool and which takes 'int' and 'int' as
    // params

    // The `&` is optional; if we don't use it, the compiler
    // will implicitly convert the function identifier into
    // the address of the function. This is not like the
    // fundamental types

    bool (*another_foo_ptr)(int, int){ foo };   // compiles just fine

    // Likewise, function pointers can be assigned `nullptr`

    another_foo_ptr = nullptr;
}
