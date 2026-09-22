


template <typename T>
class Threadsafe_queue
{
public:
    void push(T value) {
        std::lock_guard<std::mutex> lock{ m_mut };
        m_queue.push(value);
    }

    bool try_pop(T& value) {
        std::lock_guard<std::mutex> lock{ m_mut };
        if (m_queue.empty()) {
            return false;
        }

        value = m_queue.front();
        m_queue.pop();
        return true;
    }

private:
    std::queue<T> m_queue{};
    std::mutex    m_mut{};
};


class Thread_pool
{
public:
    Thread_pool() {
        // Create threads, and push them into the queue
        const std::size_t thread_count{ 2 };
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


void fun1()
{
    std::cout << "Inside fun1\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}


void fun2()
{
    std::cout << "Inside fun2\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}

void fun3()
{
    std::cout << "Inside fun3\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}

void fun4()
{
    std::cout << "Inside fun4\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}

int main()
{
    Thread_pool tpool{};
    tpool.add_task(fun1);
    tpool.add_task(fun2);
    tpool.add_task(fun3);
    tpool.add_task(fun4);
}
