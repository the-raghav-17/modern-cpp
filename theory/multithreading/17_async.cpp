#include <future>
#include <thread>
#include <iostream>


// std::async allows us to run a function in a separate
// thread and only be concerned with the return value
// without worrying about handling the thread.
//
// Whether std::async starts a new thread depends on the
// implementation. But its behavior can be tweaked using
// std::launch::deferred or std::launch::async parameters


int some_operation_that_returns_a_value()
{
    std::cout << "inside the function\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(750));
    return 1234;
}


int main()
{
    std::future<int> some_value{
        std::async(some_operation_that_returns_a_value)
    };

    std::this_thread::sleep_for(std::chrono::milliseconds(750));
    std::cout << "About to call .get() inside main\n";
    std::cout << some_value.get();
}
