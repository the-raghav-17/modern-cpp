#ifndef FUNCTION_WRAPPER_H_
#define FUNCTION_WRAPPER_H_


class Function_wrapper
{
public:
    template<typename F>
    Function_wrapper(F&& f):
        m_impl{ new Impl_type<F>(std::move(f)) }
    {}

    void operator() () { m_impl->call(); }

    Function_wrapper()=default;
    
    Function_wrapper(Function_wrapper&& other):
        m_impl{ std::move(other.m_impl) }
    {}

    Function_wrapper& operator=(Function_wrapper&& other) {
	m_impl = std::move(other.m_impl);
	return *this;
    }

    Function_wrapper(const Function_wrapper&)=delete;
    Function_wrapper(Function_wrapper&)=delete;
    Function_wrapper& operator=(const Function_wrapper&)=delete;
    
private:
    struct Impl_base {
	virtual void call()=0;
	virtual ~Impl_base() {}
    };

    std::unique_ptr<Impl_base> m_impl{};

    template<typename F>
    struct Impl_type : Impl_base {
	F m_f{};
        Impl_type(F&& f): m_f{ std::move(f) } {}
	void call() { m_f(); }
    };
};


#endif // FUNCTION_WRAPPER_H_
