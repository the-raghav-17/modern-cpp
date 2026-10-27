#include <thread>
#include <iostream>
#include <future>

int some_fun(double d, bool b)
{
    std::cout << "Inside some_fun\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    return 42;
}


int main()
{
    std::packaged_task<int(double, bool)> task{ some_fun };
}
