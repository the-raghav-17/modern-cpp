/*
 * Simple producer consumer notification system
 * using condition objects
 */


#include <iostream>
#include <thread>
#include <queue>
#include <mutex>
#include <condition_variable>


std::queue<int>         data_queue{};
std::mutex              mut{};
std::condition_variable cond{};


void
producer()
{
    std::lock_guard<std::mutex> lock{ mut };
    std::cout << "Producer acquired the lock\n";
    for (int i = 0; i < 5; i++) {
        data_queue.push(i);
    }

    std::cout << "Producer about to notify the consumer\n";
    cond.notify_one();
}


void
consumer()
{
    std::unique_lock<std::mutex> lock{ mut };
    cond.wait(lock, [](){ return !data_queue.empty(); });
    std::cout << "Consumer recieved the notification\n";

    while (!data_queue.empty()) {
        std::cout << data_queue.front() << '\n';
        data_queue.pop();
    }
}


int
main()
{
    std::thread p{ producer };
    std::thread c{ consumer };

    p.join();
    c.join();
}
