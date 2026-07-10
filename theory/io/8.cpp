/*
 * Using streambuf and file IO to
 * read a binary file (img.png in this case)
 * and copying its content to another file
 */


#include <iostream>
#include <fstream>
#include <sstream>
#include <thread>


int main()
{
    // Read the file
    std::ifstream read_file{ "test_file" };
    std::ofstream write_file{ "new_file" };

    std::this_thread::sleep_for(std::chrono::milliseconds(5000));

    // std::stringstream sbuf{};
    // sbuf << read_file.rdbuf();
    // write_file << sbuf.str();
    
    write_file << read_file.rdbuf();

    std::this_thread::sleep_for(std::chrono::milliseconds(5000));
}
