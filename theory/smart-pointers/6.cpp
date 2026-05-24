/*
 * Implementing deep copy of resource
 */


#include <iostream>


template <typename T>
class Smart_ptr
{
public:
    Smart_ptr(T *ptr=nullptr):
        m_ptr { ptr }
    {
    }

    ~Smart_ptr()
    {
        delete m_ptr;
    }

    Smart_ptr(const Smart_ptr &a)
    {
        m_ptr = new T;
        *m_ptr = *a.m_ptr;
    }

    Smart_ptr &operator=(const Smart_ptr &a)
    {
        if (&a == this) {
            return *this;
        }

        // delete any resource we're holding
        delete m_ptr;

        m_ptr = new T;
        *m_ptr = *a.m_ptr;

        return *this;
    }

private:
    T *m_ptr {};
};


class Resource
{
public:
    Resource()
    {
        std::cout << "Resource acquired\n";
    }

    ~Resource()
    {
        std::cout << "Resource released\n";
    }
};


Smart_ptr<Resource> generate_resource()
{
    Smart_ptr<Resource> res{ new Resource };
    return res;
}


int main()
{
    Smart_ptr<Resource> main_res;
    main_res = generate_resource();

    return 0;
}
