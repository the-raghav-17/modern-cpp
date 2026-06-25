// Creating a thread that calls the callabe function `operator` of a class

#include <iostream>
#include <thread>


class Background_task
{
public:
    void operator()()
    {
        std::cout << "Doing some work...\n";
    }
};


int main()
{
    Background_task obj{};
    std::thread t{ obj };
    t.join();

    // Another way: create temporary object
    std::thread t2{ Background_task{} };
    t2.join();
}
