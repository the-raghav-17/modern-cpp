#ifndef THREADPOOL_H_
#define THREADPOOL_H_


#include "threadsafe_queue.h"
#include "thread_vector.h"

#include <functional>


class Threadpool
{
public:
    Threadpool() noexcept;
    void add_task(std::function<void()> task) noexcept;

private:
    static constexpr int THREAD_COUNT{ 10 };

    Thread_vector                           m_threads{};
    Threadsafe_queue<std::function<void()>> m_task_queue{};

    void worker_thread();
};


#endif // THREADPOOL_H_
