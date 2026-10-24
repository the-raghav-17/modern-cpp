#ifndef THREADSAFE_QUEUE_H_
#define THREADSAFE_QUEUE_H_


#include <queue>
#include <mutex>
#include <condition_variable>


/**
 * Wrapper class to make queue operations threadsafe
 */
template<typename T>
class Threadsafe_queue
{
public:
    Threadsafe_queue()=default;

    /**
     * Copy constructor and operator
     */
    Threadsafe_queue(const Threadsafe_queue&);
    Threadsafe_queue& operator=(const Threadsafe_queue&);

    /**
     * Move constructor and operator
     */
    Threadsafe_queue(Threadsafe_queue&&);
    Threadsafe_queue& operator=(Threadsafe_queue&&);

    /**
     * Constructors to wrap a simple queue
     */
    Threadsafe_queue(const std::queue<T>&);
    Threadsafe_queue(std::queue<T>&&);

    ~Threadsafe_queue()=default;

    /**
     * Copies the value
     */
    void push(const T&);

    /**
     * Moves the value
     */
    void push(T&&);

    /**
     * Pop the value if it exists and return true
     * Otherwise return false
     */
    bool try_pop(T&);

    /**
     * If queue isn't empty, immediately pop the value and
     * return it. Otherwise, wait for some other thread to
     * push some value into the queue first, then pop it
     * and return it
     */
    T    wait_and_pop();

    bool empty() const;

private:
    std::queue<T>           m_queue{};
    std::mutex              m_mut{};
    std::condition_variable m_cond{};
};


template<typename T>
Threadsafe_queue<T>::Threadsafe_queue(const Threadsafe_queue& queue):
    m_queue{ queue.m_queue }
{
}


template<typename T>
Threadsafe_queue<T>&
Threadsafe_queue<T>::operator=(const Threadsafe_queue& queue)
{
    if (this == &queue) {
        return *this;
    }
    this->m_queue = queue.m_queue;
    return *this;
}


template<typename T>
Threadsafe_queue<T>::Threadsafe_queue(Threadsafe_queue&& queue):
    m_queue{ std::move(queue.m_queue) }
{
}


template<typename T>
Threadsafe_queue<T>&
Threadsafe_queue<T>::operator=(Threadsafe_queue&& queue)
{
    if (this == &queue) {
        return *this;
    }
    this->m_queue = std::move(queue.m_queue);
    return *this;
}


template<typename T>
Threadsafe_queue<T>::Threadsafe_queue(const std::queue<T>& queue):
    m_queue{ queue.m_queue }
{
}


template<typename T>
Threadsafe_queue<T>::Threadsafe_queue(std::queue<T>&& queue):
    m_queue{ std::move(queue.m_queue) }
{
}


template<typename T>
void
Threadsafe_queue<T>::push(const T& value)
{
    std::lock_guard<std::mutex> lock{ m_mut };
    m_queue.push(value);
    m_cond.notify_one();
}


template<typename T>
void
Threadsafe_queue<T>::push(T&& value)
{
    std::lock_guard<std::mutex> lock{ m_mut };
    m_queue.push(std::move(value));
    m_cond.notify_one();
}


template<typename T>
bool
Threadsafe_queue<T>::try_pop(T& value)
{
    std::lock_guard<std::mutex> lock{ m_mut };
    if (m_queue.empty()) {
        return false;
    }

    value = m_queue.top();
    m_queue.pop();
    return true;
}


template<typename T>
T
Threadsafe_queue<T>::wait_and_pop()
{
    std::unique_lock<std::mutex> lock{ m_mut };
    m_cond.wait(lock, [this]{ return !m_queue.empty(); });

    auto val{ m_queue.top() };
    m_queue.pop();
    return val;
}


template<typename T>
bool
Threadsafe_queue<T>::empty() const
{
    std::lock_guard<std::mutex> lock{ m_mut };
    return m_queue.empty();
}


#endif // THREADSAFE_QUEUE_H_
