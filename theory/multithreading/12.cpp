/*
 * Creating a thread on a member function of an
 * object, but the object also contains a mutex
 */


#include <mutex>
#include <thread>


class Test
{
public:
    void some_fun() const noexcept;

private:
    std::mutex m_mut{};
};


int main()
{
    Test test{};

    // Only this is correct form
    std::thread t{ &Test::some_fun, &test };

    // This will produce an error
    std::thread t2{ &Test::some_fun, test };
}
