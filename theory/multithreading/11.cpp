/*
 * Creating a thread by calling a member function
 * of an object directly
 */


#include <mutex>
#include <thread>


class Test
{
public:
    void some_fun() const noexcept;
};


int main()
{
    Test test{};

    // Both will compile fine
    std::thread t{ &Test::some_fun, &test };
    std::thread t2{ &Test::some_fun, test };
}
