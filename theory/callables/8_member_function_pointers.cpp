#include <iostream>


struct Test
{
    bool foo(int, double);
};


bool
Test::foo(int i, double d)
{
    std::cout << "Successfully invoked foo\n";
    return true;
}


int main()
{
    // We need to make a pointer that points to
    // the function `foo` inside of the struct `Test`

    // The declaration of this pointer is almost similar
    // to declaring a normal free function pointer, except
    // that we need to include the scope of the class
    // in which the function to be pointed at resides.
    //
    // On the RHS, we need to give the address of the
    // non-static member function. This must be exactly
    // like `&Type::Function`, otherwise, it won't work
    bool (Test::*foo_ptr)(int, double) = &Test::foo;

    Test test_obj{};
    (test_obj.*foo_ptr)(10, 20.5);
}
