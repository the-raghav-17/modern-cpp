#include "threadpool.h"

#include <iostream>
#include <vector>


void some_task()
{
    static int num{ 1 };
    std::cout << "Num value: " << num << '\n';
    num += 1;
}


int main()
{
    Threadpool tpool{};

    std::vector<std::function<void()>> tasks(10, some_task);

    for (const auto& task : tasks) {
        tpool.add_task(task);
    }
}
