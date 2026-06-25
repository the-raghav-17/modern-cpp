// Creating a thread with a lambda as an argument

#include <iostream>
#include <thread>


void do_some_work()
{
    std::cout << "Doing some work...\n";
}


void do_some_other_work()
{
    std::cout << "Doing some other work...\n";
}


int main()
{
    std::thread thread{ [](){
        do_some_work();
        do_some_other_work();
    } };

    thread.join();
}
