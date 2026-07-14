#include <iostream>
#include <optional>


[[nodiscard]] constexpr std::optional<double>
divide(double a, double b)
{
    if (b == 0) {
        return {};
        // or
        // return std::nullopt;
        // return { std::nullopt };
    }
    return a/b;
}


int main()
{
    auto res{ divide(100, 0) };
    std::cout << "Result: ";

    if (res) {
        std::cout << *res << '\n';
    } else {
        std::cout << "Invalid\n";
    }
}
