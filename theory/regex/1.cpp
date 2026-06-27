#include <regex>
#include <iostream>
#include <string>


int main()
{
    std::string line{ "GET // HTTP/1.0" };
    std::regex pat{ "(GET|POST|HEAD) /([a-z 0-9]\\.?*/?)* HTTP/1\\.(0|1)" };
    std::smatch matches{};

    if (std::regex_search(line, matches, pat) == true) {
        std::cout << matches[0] << '\n';
    } else {
        std::cout << "False\n";
    }
}
