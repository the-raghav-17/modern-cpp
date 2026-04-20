#include "util.h"

#include <random>


int Util::generate_int(const int begin, const int end)
{
    std::random_device rd;
    std::mt19937 gen(rd());

    // Distribution in range [a, b]
    std::uniform_int_distribution<std::mt19937::result_type> dist6(begin, end);

    int random_num = dist6(gen);
    return random_num;
}
