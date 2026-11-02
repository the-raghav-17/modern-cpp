#include "thread_vector.h"

#include <vector>
#include <thread>


Thread_vector::~Thread_vector()
{
    for (auto& thread : m_vector) {
        if (thread.joinable()) {
            thread.join();
        }
    }
}


void Thread_vector::push_back(std::thread&& thread) noexcept
{
    m_vector.push_back(std::move(thread));
}
