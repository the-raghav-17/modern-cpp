// Generic C++ function that can take
// any callable and its arguments and
// also returns the value if the callable


#include <type_traits>
#include <iostream>


template<typename F, typename... Args>
typename std::invoke_result<F, Args...>::type
execute_callable(F&& f, Args&&... arg)
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


void
foo()
{
    std::cout << "Inside foo\n";
}


int
foo2(int i, bool b)
{
    std::cout << "Inside foo2\n";
    return 100;
}


int main()
{
    execute_callable(foo);
    auto ret = execute_callable(foo2, 100, false);
    std::cout << ret << '\n';
}
