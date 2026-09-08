#include <queue>
#include <iostream>
#include <mutex>
#include <condition_variable>


template <typename T>
class Threadsafe_queue
{
public:
    Threadsafe_queue();

    void push(T value) {
        std::lock_guard<std::mutex> lock{ m_mut };
        m_queue.push(value);
        m_cond.notify_one();
    }

    T wait_and_pop() {
        std::unique_lock<std::mutex> lock{ m_mut };

        if (m_queue.empty()) {
            m_cond.wait(lock, [this](){ return !m_queue.empty(); });
        }

        T value{ m_queue.front() };
        m_queue.pop();
        return value;
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

    bool empty() {
        std::lock_guard<std::mutex> lock{ m_mut };
        return m_queue.empty();
    }

private:
    std::queue<T>           m_queue{};
    std::mutex              m_mut{};
    std::condition_variable m_cond{};
};
