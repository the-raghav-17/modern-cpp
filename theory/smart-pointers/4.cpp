/*
 * Implementing move semantics in our smart pointer class
 */


#include <iostream>


template <typename T>
class My_ptr
{
public:
    My_ptr(T *ptr=nullptr)
        : m_ptr { ptr }
    {
    }

    // This copy constructor is called whenever a new object
    // has to be created or a functions takes the object as parameter.
    // It simply moves ownership to the new object
    My_ptr(My_ptr &a)
    {
        std::cout << "Resource moved\n";
        m_ptr   = a.m_ptr;
        a.m_ptr = nullptr;  // ensure the original owner doesn't have any copy left
    }

    ~My_ptr()
    {
        delete m_ptr;
    }

    // Overloaded operators
    //
    // Assignment operator for moving ownership
    My_ptr &operator=(My_ptr &ptr)
    {
        if (&ptr == this) {
            return *this;
        }

        // Firstly, clean up any pointer we're holding
        delete m_ptr;

        m_ptr = ptr.m_ptr;
        ptr.m_ptr = nullptr;
    }

    // -> and * operators
    T &operator*() const { return *m_ptr; }
    T *operator->() const { return m_ptr; }

    bool is_null() const { return m_ptr == nullptr; }

private:
    T *m_ptr {};
};


class Resource
{
public:
    Resource() { std::cout << "Resource acquired\n"; }
    ~Resource() { std::cout << "Resource destroyed\n"; }
};


void do_nothing(const My_ptr<Resource> r_ptr)  // r_ptr = r_ptr2
{
}


int main()
{
    // r_ptr now behaves like a simple smart pointer
    My_ptr<Resource> r_ptr{ new Resource{} };

    // Trying to move resource
    My_ptr<Resource> r_ptr2 { r_ptr };
    do_nothing(r_ptr2);
}
