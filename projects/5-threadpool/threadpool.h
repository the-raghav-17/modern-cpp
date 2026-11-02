/**
 * A simple threadpool implementation that
 * can take any callable with any number of
 * arguments and retunrs a future associated
 * with the return value
 */


#ifndef THREADPOOL_H_
#define THREADPOOL_H_

#include <thread>
#include <future>
#include <functional>

#include "threadsafe_queue.h"
#include "thread_vector.h"
#include "function_wrapper.h"


class Threadpool
{
public:
    /**
     * Constructor creates a fixed number of
     * threads and stores them in the vector
     */
    Threadpool();

    /*
     * add_task() functions adds any generic
     * callable into the tasks queue and returns
     * a future associated with the callable
     */
    template<typename F, typename... Args>
    std::future<std::invoke_result_t<F, Args...>>
    add_task(F&& f, Args&&... args);

private:
    static constexpr int               m_THREAD_COUNT{ 10 };

    Thread_vector                      m_threads{};
    Threadsafe_queue<Function_wrapper> m_tasks_queue{};

    void worker_thread();
    
};


Threadpool::Threadpool()
{
    for (int i = 0; i < m_THREAD_COUNT; i++) {
	// Start the thread in the worker_thread
	// member function
	std::thread thread{ &Threadpool::worker_thread,
		            this };
	m_threads.push_back(std::move(thread));
    }    
}


template<typename F, typename... Args>
std::future<std::invoke_result_t<F, Args...>>
Threadpool::add_task(F&& f, Args&&... args)
{
    using Return_type = std::invoke_result_t<F, Args...>;

    // Abstract away the argument details
    auto func = std::bind(f, args...);

    // Get the future
    std::packaged_task<Return_type()> packaged_task{ func };
    auto future = packaged_task.get_future();

    // The packaged_task object now acts as the
    // callable with return type void. Now wrap
    // this packaged_task in Function_wrapper
    Function_wrapper task{ packaged_task };
    m_tasks_queue.push(task);
    
    return future;
}


void
Threadpool::worker_thread()
{
    while (1) {
	Function_wrapper task{};
	if (m_tasks_queue.try_pop(task)) {
	    task();
	} else {
	    std::this_thread::yield();
	}
    }
}


#endif // THREADPOOL_H_
