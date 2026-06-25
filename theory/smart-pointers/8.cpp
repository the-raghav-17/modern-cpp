#include <string>
#include <iostream>


class Test
{
public:
    explicit Test() :        // default constructor
        m_int{ 10 },
        m_str{ "hello" }
    {
        std::cout << "Default constructor invoked\n";
    }

    Test(Test& t):   // copy constructor
        m_int{ t.m_int },
        m_str{ t.m_str }
    {
        std::cout << "Copy constructor invoked\n";
    }

    Test(Test&&) = delete;
    // Test(Test&& t):   // move constructor
    //     m_int{ t.m_int },
    //     m_str{ t.m_str }
    // {
    //     t.m_int = -1;
    //     t.m_str = "";
    //     std::cout << "Move constructor invoked\n";
    // }

    int m_int{};
    std::string m_str{};
};


Test return_test()
{
    Test t{};
    t.m_int = 567;
    t.m_str = "new string";
    return t;
}

int main()
{
    Test t( return_test() );
    std::cout << "m_int: " << t.m_int << "  m_str: " << t.m_str << '\n';
}
