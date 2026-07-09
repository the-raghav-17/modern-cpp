/*
 * Unformatted input using std::cin object which is
 * defined in iostream header and is an object of type 
 * basic_istream<char>. The underlying streambuf of this
 * object is set to the keyboard or stdin
 */


#include <iostream>
#include <fstream>
#include <cstdint>


int main()
{
    /*
     * Other than .get() method, we also have .read() method,
     * which reads multiple characters instead of just one
     */

    // Create a binary file to store some binary data
    std::ofstream outfile{ "binary_file", std::ios::binary | std::ios::out };
    uint8_t msg[3]{ 60, 61, 62 };    // <=>
    outfile.write(reinterpret_cast<char*>(msg), sizeof(msg));
    outfile.close();

    std::ifstream infile{ "binary_file", std::ios::binary | std::ios::in };

    // Now read from that same file
    uint8_t buf[3];
    infile.read(reinterpret_cast<char*>(buf), sizeof(buf));
    std::cout.write(reinterpret_cast<char*>(buf), sizeof(buf));
    std::cout << '\n' << buf;
}
