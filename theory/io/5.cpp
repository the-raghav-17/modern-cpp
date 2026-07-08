/*
 * Unformatted input using std::cin object which is
 * defined in iostream header and is an object of type 
 * basic_istream<char>. The underlying streambuf of this
 * object is set to the keyboard or stdin
 */


#include <iostream>
#include <cstdio>


int main()
{
    /*
     * Unformatted input in std::cin can be done
     * using the .get() and .read() methods. There
     * are also other helper methods available that
     * provide much more control over the characters
     * in the stream
     */

    /*
     * The get method simply extracts a single character
     * from the stream without formatting it. If any kind of
     * formatting happens, its due to the type it casted to
     */

    char ch{};
    ch = std::cin.get();  // type '123'
    std::cout << ch;      // outputs 1

    /*
     * In the above code, out of 123, only 1 is
     * captured by cin.get(), the rest 23 are kept
     * in the stream. After 1 is captured, its converted
     * to its ascii value => 49. When this 49 is captured
     * by ch, its converted back to its character form '1'
     */

    // Empty that stream. I don't know if this
    // while loop is idiomatic cpp or not. I just
    // want to do it right now, instead of focusing on 
    // best practices
    while (std::cin.get() != '\n');

    std::cout << '\n';

    int var{};
    var = std::cin.get(); // again input '123'
    std::cout << var;     // this prints 49

    /*
     * Here we captured the ascii value of '1' into
     * var, which is of type int. This ascii value
     * is printed as it is.
     */
}
