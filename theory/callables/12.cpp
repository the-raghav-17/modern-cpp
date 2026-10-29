// Writing a generic function execute_callable
// that takes a callable and its arguments and
// then executes it. Doesn't provide any method of
// returning back the values (yet)

#include <iostream>
#include <string>


template<typename F, typename... Arg>
void execute_callable(F&& f, Arg&&... args)
{
    f(args...);
}


void print_values(int i, const std::string& s,
		  bool b, double d)
{
    std::cout << "Printing values:\n"
	      << "Integer: " << i << '\n'
	      << "String: " << s << '\n'
	      << "Boolean: " << b << '\n'
	      << "Double: " << d << '\n';
}


int main()
{
    execute_callable(print_values, 123, "Hello", false, 3.14);
}
