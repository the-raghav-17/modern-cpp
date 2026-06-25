// 

#include <iostream>
#include <thread>


struct Func
{
public:
    Func(int& i): m_i{ i } {}

    void operator()()
    {
        for (auto i = 0; i < 10000000000; i++) {
            std::cout << m_i << '\n';
        }
    }

private:
    int& m_i;  // this reference to i might become dangling once the original i is destroyed
};


void oops()
{
    int i{ 100 };
    Func f{ i };
    std::thread my_thread{ f };
    my_thread.detach();
} // i is destroyed here


int main()
{
    oops();
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
}
