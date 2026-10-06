#ifndef THREAD_VECTOR_H_
#define THREAD_VECTOR_H_

#include <vector>
#include <thread>


/**
 * Wrapper class around std::vector<std::thread>
 * to automatically join threads on object destruction
 */
class Thread_vector
{
public:
    Thread_vector()=default;

    /**
     * Destructor joins the threads
     * in the vector
     */
    ~Thread_vector() noexcept;

    /**
     * Push the thread into the vector
     */
    void push_back(std::thread&& thread) const noexcept;

private:
    std::vector<std::thread> m_vector{};
};


#endif // THREAD_VECTOR_H_
