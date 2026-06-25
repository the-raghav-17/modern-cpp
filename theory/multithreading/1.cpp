// Creating a basic thread

#include <thread>
#include <iostream>


void do_some_work()
{
    std::cout << "Doing some work...\n";
}


int main()
{
    std::cout << "Inside main thread...\n";

    std::thread thread{ do_some_work };
    std::cout << "New thread created...\n";

    std::cout << "Waiting for thread to finish...\n";
    thread.join();
    std::cout << "Thread finished execution...\n";
}
