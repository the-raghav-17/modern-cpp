/**
 * Solution to problem in 5.cpp - Use a thread wrapper
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


class Thread_wrapper
{
public:
    Thread_wrapper(std::thread& thread):
        m_thread{ thread }
    {}

    ~Thread_wrapper()
    {
        m_thread.join();
    }

private:
    std::thread& m_thread;
};


int main()
{
    Func obj{};

    std::thread thread{ obj };
    Thread_wrapper wrapper{ thread };

    try {
        toy();
    }
    catch(const std::runtime_error& err) {
        std::cout << "Exception caught: " << err.what() << '\n';
        return 1;
    }
}
