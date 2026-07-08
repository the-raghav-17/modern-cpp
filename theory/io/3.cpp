/*
 * Unformatted output using std::cout object which is
 * defined in iostream header and is an object of type 
 * basic_ostream<char>. The underlying streambuf of this
 * object is set to the terminal/display/screen
 */


#include <iostream>


int main()
{
    /*
     * In order to perform block output, we would use
     * write method defined in class basic_ostream.
     */

    /*
     * write works by taking a pointer/buffer to the data
     * to write and size of that buffer. It then simply
     * outputs that data without doing any kind of
     * formatting.
     */

    struct Test_datatype
    {
        int i{};
        char ch{};
        double d{};
    };

    Test_datatype test{ 65, 'r', 1.02 };

    // Now we will print this test data without
    // first converting into human readable form.
    //
    // We would need to cast test to pointer of type
    // char.

    std::cout.write(reinterpret_cast<char*>(&test), sizeof(test));

    // This will probably spit out some random garbage on the terminal
    // but it is effectively what the binary representation of this data
    // test represents in human readable form
}
