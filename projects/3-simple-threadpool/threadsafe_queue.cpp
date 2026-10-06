#include "threadsafe_queue.h"

#include <queue>
#include <thread>
#include <mutex>


template <typename T>
void
Threadsafe_queue<T>::push(T value) noexcept
{
    std::lock_guard<std::mutex> lock{ m_mut };
    m_queue.push(value);
}


template <typename T>
void
Threadsafe_queue<T>::push(T&& value) noexcept
{
    std::lock_guard<std::mutex> lock{ m_mut };
    m_queue.push(std::move(value));
}


template <typename T>
bool
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
