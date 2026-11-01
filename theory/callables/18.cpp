#include <type_traits>
#include <iostream>
#include <functional>


template<typename F, typename... Args>
typename std::invoke_result<F, Args...>::type
execute_callable(F&& f, Args&&... args)
{
    using Ret_type = typename std::invoke_result<F, Args...>::type;
    
    auto fun = std::bind(f, args...);
    
    if constexpr (!std::is_void_v<Ret_type>) {
	auto ret = fun();
	return ret;
    }

    fun();
}


template<typename F, typename... Args>
typename std::invoke_result<F, Args...>::type
execute_callable2(F&& f, Args&&... arg)
{
    using Ret_type = typename std::invoke_result<F, Args...>::type;
    if constexpr (!std::is_void_v<Ret_type>) {
	std::cout << "Type is non-void\n";
	auto ret = f(arg...);
	return ret;
    }

    std::cout << "Type is void\n";
    f(arg...);
}



int main()
{
    auto callable = []{ return 1000; };
    execute_callable(callable);
}
