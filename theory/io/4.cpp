/*
 * Formatted input using std::cin object which is
 * defined in iostream header and is an object of type 
 * basic_istream<char>. The underlying streambuf of this
 * object is set to the keyboard or stdin
 */


#include <iostream>


int main()
{
    /*
     * Formatted input in std::cin can be done
     * operator>>
     */

    char var1;
    std::cin >> var1;  // type 'a'

    std::cout << var1; // prints 'a'


    int var2;
    std::cin >> var2;   // type 1234
    std::cout << var2;

    // the object cin knows that var2 is of type
    // integer, so when the user types 1234, it 
    // marks it as a valid input and converts that
    // input into integer form

    // If the user doesn't input the expected type, the
    // cin object will not behave properly.
}
