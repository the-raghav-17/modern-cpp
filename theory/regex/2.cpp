#include <regex>
#include <iostream>
#include <string>


int main()
{
    const std::string msg{ "GET / HTTP/1.0" };
    const std::regex pattern{ "(GET|POST|HEAD) /([a-z 0-9]*\\.[a-z 0-9]*)*/? HTTP/1\\.(0|1)" };

    std::cout << std::regex_match(msg, pattern) << '\n';
}
