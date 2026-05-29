#include <iostream>


int main()
{
    /*
     * A const reference can also refer to non-const l-values.
     * Unlike a non-const reference, a const reference also allows
     * narrowing and conversions.
     *
     * This means if l-value is of type int and const reference is of
     * type double, conversion will occur.
     *
     * But this conversion won't affect the original variable the reference
     * is supposed to refer. Instead, a new temporary object will be created
     * with the narrowed value and the reference than points to that temporary.
     *
     * A consequence of this is that if we try to change our original variable, 
     * no change will occur in the value of reference, because it points to a
     * temporary, whose value remains unaffected.
     */
    
    int y { 888 };           // y is of type int
    const double& ref3 = y;

    y = 123;

    std::cout << ref3 << '\n';
}
