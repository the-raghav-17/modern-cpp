/*
 * Formatted output using std::cout object which is
 * defined in iostream header and is an object of type 
 * basic_ostream<char>. The underlying streambuf of this
 * object is set to the terminal/display/screen
 */


#include <iostream>


int main()
{
    std::cout << "Formatted IO\n";
    std::cout << 42 << '\n';      // Automatically converts 42 to human readable text form
}
