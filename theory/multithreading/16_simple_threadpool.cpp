#include <thread>
#include <mutex>
#include <atomic>
#include <vector>


class Thread_pool
{
public:
    /**
     * Creates worker threads and appends them into
     * the threads vector
     */
    Thread_pool():
        m_done{ false },
        m_joiner{ m_threads }
    {
        const unsigned thread_count{ std::thread::hardware_concurrency() };

        try {
            for (unsigned i = 0; i < thread_count; i++) {
                // Create a worker thread and append it inside the pool
                m_threads.push_back(
                    std::thread{ &Thread_pool::worker_thread, this } );
            }
        }
        catch (...) {
            done = true;
            throw;
        }
    }

    ~Thread_pool() {
        done = true;
    }

    /**
     * Method to submit tasks to the threadpool
     */
    template <typename Function_type>
    void submit(Function_type f) {
        m_task_queue.push(std::function<void()>(f));
    }

private:
    std::vector<std::thread>                m_threads{};
    Threadsafe_queue<std::function<void()>> m_task_queue{};
    Join_threads                            m_joiner{};
    std::atomic<bool>                       m_done{};


};
