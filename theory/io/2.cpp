/*
 * Unformatted output using std::cout object which is
 * defined in iostream header and is an object of type 
 * basic_ostream<char>. The underlying streambuf of this
 * object is set to the terminal/display/screen
 */


#include <iostream>
#include <cstdint>


int main()
{
    /*
     * We can achieve unformatted IO (which doesn't convert
     * the data into human readable form) using the write() and
     * put() method defined in an object of type `basic_ostream`
     */

    /*
     * put works on a single character. write works on block of
     * characters
     */

    uint8_t i{ 42 };    // i is of type unsigned 8-bit integer

    std::cout.put(static_cast<char>(i));

    /*
     * put takes a single argument of type character
     * we will cast i to a character type. Now 42 will not
     * be converted to human readable form. Instead, it will
     * be printed as binary `00101010`. When the terminal sees
     * this character sequence, it knows that it is the ascii
     * code for the characater `*` and hence prints that instead
     */
}
