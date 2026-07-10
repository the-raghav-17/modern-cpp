/*
 * C++ string stream objects. A stringstream object is
 * an extension of the fundamental stream classes, and
 * provides exclusive/specialized features for dealing 
 * with strings.
 *
 * It can be created using a simple stringstream object,
 * or by first creating a stringbuf object and then wrapping
 * it around iostream object, which helps to do actual IO
 */


#include <sstream>
#include <iostream>


int main()
{
    std::stringbuf sbuf{ std::ios::in | std::ios::out };
    std::iostream  sio{ &sbuf };

    // Formatted output
    sio << "Hello";

    // Unformatted output
    int ch{ 65 };
    sio.put(static_cast<char>(ch));

    // Getting the string in the underlying raw device
    std::cout << sbuf.str();
}
