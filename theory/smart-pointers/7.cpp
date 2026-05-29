/*
 * Implementing move constructor and move assignment
 */


#include <iostream>


template <typename T>
class Smart_pointer
{
public:
    Smart_pointer(T* ptr=nullptr):
        m_ptr { ptr }
    {
    }

    ~Smart_pointer()
    {
        delete m_ptr;
    }

    // move constructor
    Smart_pointer(Smart_pointer&& a) noexcept:
        m_ptr { a.m_ptr }
    {
        a.m_ptr = nullptr;
    }

    Smart_pointer& operator=(Smart_pointer&& a) noexcept
    {
        // Self assignment detection
        if (&a == this) {
            return *this;
        }

        delete m_ptr;
        m_ptr = a.m_ptr;
        a.m_ptr = nullptr;

        return *this;
    }

private:
    T* m_ptr {};
};


class Resource
{
public:
    Resource() { std::cout << "Resource acquired\n"; }
    ~Resource() { std::cout << "Resource destroyed\n"; }
};


Smart_pointer<Resource> get_resource()
{
    Smart_pointer<Resource> res { new Resource() };
    return res;
}


int main()
{
    Smart_pointer<Resource> mainres;
    mainres = get_resource();
}
