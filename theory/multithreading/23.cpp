#include <iostream>
#include <future>
#include <thread>


int some_fun(bool b, double d)
{
    std::cout << "Inside some_fun\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    return 42;
}


int main()
{
    // Here's the problem: We successfully ran some_fun in a different
    // thread, but how do we get it's return value??? The std::thread
    // object/class doesn't provide a neat mechanism for that.

    // Using std::async and std::future

    // std::future<int> ret_val{ std::async(some_fun, true, 13.4) };
    // std::cout << "Return value: " << ret_val.get() << '\n';

    // Using std::packaged_task
    std::packaged_task<int(bool, double)> task{ some_fun };

    // Get the future associated with the packaged task
    auto task_future{ task.get_future() };

    // Execute the task
    task(true, 34.12);

    std::cout << "Return value: " << task_future.get() << '\n';
}
