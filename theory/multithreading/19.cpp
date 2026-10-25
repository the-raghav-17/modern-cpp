#include <functional>
#include <iostream>
#include <thread>


bool
fun(int i)
{
    return true;
}


void
wrapper_around_fun(int fun_arg, bool& fun_ret)
{
    fun_ret = fun(fun_arg);
}


void
foo(int& i)
{

}


int main()
{
    // bool var{ fun(10) };
    // std::cout << var << '\n';

    // We want to execute the function `fun`
    // in some other thread and use the return
    // value of that function in the main thread.
    //
    // So, we created a new thread using the classical
    // approach. But we immediately see the problem here.
    // The thread object doesn't have any way of passing
    // down the return value of fun.

    std::thread thread{ fun, 10 };
    thread.join();

    // One solution for this problem is to use some shared
    // variable that stores the return value

    bool fun_ret{}; // Shared variable
    std::thread t2{ wrapper_around_fun, 10, std::ref(fun_ret) };
    t2.join();

    std::cout << "Return value: " << fun_ret << '\n';

    // All of this is great but a better way of solving this problem is
    // to use std::future and std::async
}
