#include <sstream>
#include <cstdint>
#include <iostream>


int main()
{
    std::stringstream s{ std::ios::in | std::ios::out };

    // Inserting textual data
    s << "Some textual data";

    // Inserting binary data
    uint8_t arr[] = { 65, 66, 67, 68, };
    s.write(reinterpret_cast<char*>(arr), sizeof(arr));

    std::cout << s.str();
}
