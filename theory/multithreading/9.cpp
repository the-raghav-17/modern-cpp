#include <iostream>
#include <atomic>


int main()
{
    // Atomic types support assignment operations
    std::atomic<int> some_int{};
    some_int = 10;
    std::cout << some_int << '\n';

    // The return type of the assignment operation is *not*
    // a reference type, as is common among overloaded assignment
    // operations of other types. Instead it returns a value.
    //
    // This is because, in order to read the value returned if it
    // were a reference, this would mean we need to do a separate
    // read. This opens up oppurtunity for some other thread to modify
    // the value
}
