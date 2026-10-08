#include "threadpool.h"

#include <thread>
#include <functional>


Threadpool::Threadpool() noexcept
{
    for (int i = 0; i < Threadpool::THREAD_COUNT; i++) {
        std::thread thread{ &Threadpool::worker_thread, this };
        m_threads.push_back(std::move(thread));
    }
}


void
Threadpool::add_task(std::function<void()> task) noexcept
{
    m_task_queue.push(std::move(task));
}


void
Threadpool::worker_thread()
{
    while (1) {
        std::function<void()> task{};

        if (m_task_queue.try_pop(task)) {
            task();
        } else {
            std::this_thread::yield();
        }
    }
}
