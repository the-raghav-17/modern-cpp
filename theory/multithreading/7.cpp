// Atomic operations

#include <iostream>
#include <atomic>


int main()
{
    // Almost always, the atomic operations take a single set to finish.
    // This means that they either finish or don't; there's no in-between 'half-finished'
    // state.

    std::atomic<int> atomic_int{};

    // But its still possible for many atomic types to use mutex locks beneath.
    // This might be due to hardware constraints.
    // To check if an atomic variable uses mutex locks, use `X::is_always_lock_free`
    // static member (C++17 onwards)
    // Before C++17, we can use the member function `is_lock_free()` (non-static)

    std::cout << std::atomic<bool>::is_always_lock_free << '\n';
    std::cout << std::atomic<int>::is_always_lock_free << '\n';
    std::cout << std::atomic<float>::is_always_lock_free << '\n';
    std::cout << std::atomic<uintmax_t>::is_always_lock_free << '\n';
    std::cout << std::atomic<double>::is_always_lock_free << '\n';

    std::cout << atomic_int.is_lock_free() << '\n';
}
