/**
 * Forgetting to call .join in exceptional situations
 */


#include <thread>
#include <iostream>


struct Func
{
    void operator() () {
        std::cout << "Starting the new thread\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
        std::cout << "Reached here\n";
    }
};


void toy()
{
    throw std::runtime_error{ "error" };
}


int main()
{
    Func obj{};

    std::thread thread{ obj };

    try {
        toy();
    }
    catch(const std::runtime_error& err) {
        std::cout << "Exception caught: " << err.what() << '\n';
        // Can be solved by adding thread.join() here.
        // But this is not a good design
        return 1;
    }

    thread.join();
}
