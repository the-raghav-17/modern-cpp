#include <iostream>
#include <type_traits>


template<typename F, typename... Args>
typename std::invoke_result<F, Args...>::type
execute_callable(F&& f, Args&&... arg)
{
    // TODO
}


int main()
{
    auto fun1 = []{ };
    auto fun2 = [](int i){ return 100; };

    execute_callable(fun1);
    execute_callable(fun2, 100);
}
