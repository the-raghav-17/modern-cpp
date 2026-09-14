#include <iostream>


int foo()
{
    return 5;
}


int main()
{
    // when a function is called by its name
    // and the function call operator () is not
    // used, then the name refers to the pointer
    // of the function

    foo();    // calls the function
    foo;      // refers to the address of the function
              // or is a function pointer
}
