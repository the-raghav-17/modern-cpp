//
// The semantics of passing arguments to a callable via a
// thread object are a little different.
//
// When an argument is passed to a thread object, the object
// takes the argument as it is without converting it to the
// type required by the callable's argument.
//
// So, if a function takes `const std::string&` as the argument
// and we call the thread object as this `std::thread t{ f, "hello" }`
// the "hello" is treated by the thread object as a `const char*` rather
// than a `const std::string&`. It is only when the thread calls the callable
// that this type is converted to `const std::string&`
//
// This behavior can lead to undefined behavior in certain cases.
//

#include <string>
#include <thread>
#include <cstdio>


void f(int i, const std::string& s)
{

}


void oops()
{
    char buffer[1024];
    snprintf(buffer, sizeof(buffer), "hello, world");
    std::thread t{ f, 100, buffer };

    // we pass the pointer to buffer
    // which is not instantly converted
    // to const std::string&. Thus
    // there's a possibility that the oops()
    // function will exit first and destroy
    // the `buffer` which will lead to undefined
    // behavior in the thread

    t.detach();
}


int main()
{
    oops();
}
