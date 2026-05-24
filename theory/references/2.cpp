/*
 * r-value references
 */


#include <iostream>


int main()
{
    int x { 100 };

    int &&ref1 { 100 };   // ok: non-const rvalue reference can be used to 
                          // refer to r-values

    // since ref1 is non-const, this means we can also change its value
    std::cout << ref1 << '\n';
    ref1 = 123;
    std::cout << ref1 << '\n';

    // we can't assign any type of l-value to any type of
    // r-value reference
    //
    // int &&ref2 { x };
    // const int &&ref3 { x };
    //
    // const int a { 12345 };
    // const int &&ref4 { a };

    const int &&ref5 { 124141 };  // ok: ref is of type const r-value reference and
                                  // can be used to assign r-values to it. here we can't
                                  // modify the value referenced by ref5 as its const
}
