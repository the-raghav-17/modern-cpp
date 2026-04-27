#ifndef UTIL_H_
#define UTIL_H_


#include <random>


namespace Util
{
    class Random_int_generator
    {
    public:
        // generate a random int between begin and
        // end both included
        static int generate(const int begin, const int end);

    private:
        static std::random_device rd;
        static std::mt19937 gen;
    };
};


#endif // UTIL_H_
