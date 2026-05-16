/*
 * Creating simple smart pointer class
 */

#include <iostream>


template <typename T>
class My_ptr
{
public:
    My_ptr(T *ptr=nullptr):
        m_ptr{ ptr }
    {
    }

    ~My_ptr()
    {
        delete m_ptr;
    }

private:
    T *m_ptr {};

};


class Resource
{
public:
    Resource()
    {
        std::cout << "Resource Allocated...\n";
    }

    ~Resource()
    {
        std::cout << "Resource Deallocated...\n";
    }
};


int main()
{
    My_ptr<Resource> ptr{ new Resource() };
}

