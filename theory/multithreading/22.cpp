#include <future>
#include <iostream>
#include <thread>


int find_answer_to_universe()
{
    return 42; 
}


void do_other_stuff()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}


int main()
{
    // std::async runs the task in a separate thread and returns a std::future
    // The std::future then can be queried to acquire the return value from the
    // function that was run in async
    
    std::future<int> answer_to_universe{ std::async(find_answer_to_universe) };
    do_other_stuff();
    std::cout << "The answer to universe is: " << answer_to_universe.get() << '\n';
}
