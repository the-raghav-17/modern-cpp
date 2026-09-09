/**
 * A simple type to encapsulate threads and
 * join them when the object of type destroys
 */


#include <vector>
#include <thread>


class Join_threads
{
public:
    explicit Join_threads(std::vector<std::thread>& threads):
        m_threads{ threads }
    {}

    ~Join_threads() {
        for (auto& thread : m_threads) {
            if (thread.joinable()) {
                thread.join();
            }
        }
    }

private:
    std::vector<std::thread>& m_threads;
};
