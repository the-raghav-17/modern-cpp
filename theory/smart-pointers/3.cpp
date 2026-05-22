#include <iostream>
#include <memory>


std::unique_ptr<int> fun()
{
    // int *iptr { new int };
    // *iptr = 100;
    // return iptr;

    std::unique_ptr<int> iptr{ new int };
    *iptr = 100;
    return iptr;
}


int main()
{
    auto iptr = fun();
    std::cout << "Value of iptr: " << *iptr << '\n';

} // automatic deletion of iptr
