#include <iostream>
#include <type_traits>


void fun();


template<typename F, typename... Args>
decltype(F())
execute_callable(F&& f, Args&&... args)
{
    using Ret_type = decltype(f());
    if (!std::is_void_v<Ret_type>) {
	std::cout << "Function is not void\n";
	auto ret = f(args...);
	return ret;
    }

    f(args...);
}


int main()
{
    auto callable = []{ return 1000; };
    execute_callable(callable);
}
