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
    void push(T value) noexcept;
    void push(T&& value) noexcept;
    bool try_pop(T& value) noexcept;

private:
    std::queue<T> m_queue{};
    std::mutex    m_mut{};
};


#endif // THREADSAFE_QUEUE_H_
