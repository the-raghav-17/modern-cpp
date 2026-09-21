class Thread_pool
{
public:
    Thread_pool() {
        // Create threads, and push them into the queue
        const std::size_t thread_count{ std::thread::hardware_concurrency };
        for (std::size_t i = 0; i < thread_count; i++) {
            m_threads.push_back(std::thread{ &Thread_pool::worker_thread, this });
        }
    }

    ~Thread_pool() {
        for (auto& thread : m_threads) {
            if (thread.joinable()) {
                thread.join();
            }
        }
    }

    template <typename Func_type>
    void add_task(Func_type task) {
        m_task_queue.push(std::function<void()>{ task });
    }

private:
    std::vector<std::thread>                m_threads{};
    Threadsafe_queue<std::function<void()>> m_task_queue{};

    void worker_thread() {
        while (1) {
            std::function<void()> task{};
            if (m_task_queue.try_pop(task)) {
                task();
            } else {
                std::this_thread::yield();
            }
        }
    }
};
