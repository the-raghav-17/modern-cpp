#ifndef THREADPOOL_H_
#define THREADPOOL_H_


class Threadpool
{
public:
    Threadpool() noexcept;

private:
    Thread_vector                   m_threads{};
    Threadsafe_queue<std::function> m_task_queue{};

    constexpr int THREAD_COUNT{ 10 };

    void worker_thread();
};


#endif // THREADPOOL_H_
