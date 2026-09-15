#include <iostream>


void foo(int x, int y=10)
{
    if (x == y) {
        std::cout << "Both are equal\n";
    } else {
        std::cout << "Both aren't equal\n";
    }
}


int main()
{
    // For a normal function call with default args, the
    // args are written at the function call site during compile
    // time and thus no error occurs.
    // But for a function call with a function pointer, there
    // is no args writing at compile time and everything happens
    // during runtime. This means that not providing default
    // args beforehand will lead to compiler error.

    foo(10);   // default args are resolved at compile-time
               // thus is a valid function call

    void (*foo_ptr)(int, int){ &foo };

    // foo_ptr(10);  // defalut args aren't resolved at compile-time
                  // thus isn't a valid function call

    foo_ptr(10, 10);

    // This fact that function pointer calls must be resolved during
    // compile time can be used to deal with function call ambiguity

    void print(int x);
    void print(int x, int y=10);

    // print(10);    // <- This would be ambiguous as both the availabe
                     //    options are totally valid

    void (*print_ptr)(int){ print };
    print_ptr(10);   // <- This is no longer an ambiguous function call
}
