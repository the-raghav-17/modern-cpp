#include "util.h"

#include <random>


std::random_device Util::Random_int_generator::rd {};
std::mt19937       Util::Random_int_generator::gen { rd() };


int Util::Random_int_generator::generate(const int begin, const int end)
{
    // Distribution in range [a, b]
    std::uniform_int_distribution<std::mt19937::result_type> dist6(begin, end);

    int random_num = dist6(gen);
    return random_num;
}
