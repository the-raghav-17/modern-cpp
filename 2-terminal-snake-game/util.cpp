#include "util.h"

#include <random>


int Util::generate_int(const int begin, const int end)
{
    std::random_device rd;
    std::mt19937 gen(rd());

    // Distribution in range [a, b]
    std::uniform_int_distribution<> dist(begin, end);

    int random_num = dist(gen);
    return random_num;
}
