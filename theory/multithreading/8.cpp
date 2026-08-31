#include <iostream>
#include <atomic>


int main()
{
    // The standard atomic types are neither copyable
    // nor movable
    std::atomic<int> int_atomic{ 5 };
    std::atomic<int> another_int_atomic{ int_atomic };
    std::atomic<int> one_more_int_atomic{};

    one_more_int_atomic = int_atomic;
    one_more_int_atomic = std::move(int_atomic);
}
