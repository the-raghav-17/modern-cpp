#ifndef THREADSAFE_QUEUE_H_
#define THREADSAFE_QUEUE_H_

#include <queue>
#include <thread>
#include <mutex>


/**
 * Generic queue to support threadsafe
 * push and pop operations on a queue
 */
template <typename T>
class Threadsafe_queue
{
public:
    Threadsafe_queue()=default;
    void push(T& value) noexcept;
    void push(T&& value) noexcept;
    bool try_pop(T& value) noexcept;

private:
    std::queue<T> m_queue{};
    std::mutex    m_mut{};
};


template <typename T>
inline void
Threadsafe_queue<T>::push(T& value) noexcept
{
    std::lock_guard<std::mutex> lock{ m_mut };
    m_queue.push(value);
}


template <typename T>
inline void
Threadsafe_queue<T>::push(T&& value) noexcept
{
    std::lock_guard<std::mutex> lock{ m_mut };
    m_queue.push(std::move(value));
}


template <typename T>
inline bool
Threadsafe_queue<T>::try_pop(T& value) noexcept
{
    std::lock_guard<std::mutex> lock{ m_mut };

    if (!m_queue.empty()) {
        value = std::move(m_queue.front());
        m_queue.pop();
        return true;
    }

    return false;
}

#endif // THREADSAFE_QUEUE_H_
