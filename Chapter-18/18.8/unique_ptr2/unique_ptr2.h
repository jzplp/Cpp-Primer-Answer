#ifndef UNIQUE_PTR2_H
#define UNIQUE_PTR2_H

#include<memory>
#include<stdexcept>
#include<iostream>
#include<utility>

class Unique_ptr_Delete
{
public:
	Unique_ptr_Delete() noexcept = default;
	template <typename T> void operator()(T *p) const { delete p; } 
};

template <typename T, typename F> class unique_ptr2;

template <typename T, typename F>
void swap(unique_ptr2<T, F> & lhs, unique_ptr2<T, F> &rhs);

template <typename T, typename F = Unique_ptr_Delete>
class unique_ptr2
{
public:
	unique_ptr2() noexcept : p(nullptr), delFun(Unique_ptr_Delete()) { }
	unique_ptr2(T * up, F fun = Unique_ptr_Delete()) noexcept : p(up) , delFun(fun) { }
	unique_ptr2(F fun) noexcept : p(nullptr) , delFun(fun) { }
	~unique_ptr2() noexcept;
	
	explicit operator bool() const;
	T & operator*() const;
	T * operator->() const;
	T * get() const;
	void swap(unique_ptr2 &);
	
	unique_ptr2 & operator=(T * up);
	unique_ptr2(const unique_ptr2 &) = delete;
	unique_ptr2 & operator=(const unique_ptr2 &) = delete;
	unique_ptr2(unique_ptr2 &&) noexcept;
	unique_ptr2 & operator=(unique_ptr2 &&);
	
	T * release();
	void reset(T * up = nullptr);
	
private:
	T * p;
	F delFun;
};


template <typename T, typename F>
unique_ptr2<T, F>::~unique_ptr2() noexcept
{
	delFun(p);
}

template <typename T, typename F>
unique_ptr2<T, F>::operator bool() const
{
	if(p == nullptr)
		return false;
	return true;
}

template <typename T, typename F>
T & unique_ptr2<T, F>::operator*() const
{
	if(p == nullptr)
		throw std::runtime_error("no object!");
	return *p;
}

template <typename T, typename F>
T * unique_ptr2<T, F>::operator->() const
{
	return & this->operator*();
}


template <typename T, typename F>
T * unique_ptr2<T, F>::get() const
{
	return p;
}

template <typename T, typename F>
void unique_ptr2<T, F>::swap(unique_ptr2 & up)
{
	using std::swap;
	swap(p, up.p);
	swap(delFun, up.delFun);
}

template <typename T, typename F>
void swap(unique_ptr2<T, F> & lhs, unique_ptr2<T, F> &rhs)
{
	lhs.swap(rhs);
}

template <typename T, typename F>
unique_ptr2<T, F> & unique_ptr2<T, F>::operator=(T * up)
{
	if(up != nullptr)
		throw std::runtime_error("Prohibition of assignment!");
	p = nullptr;
	return *this;
}

template <typename T, typename F>
unique_ptr2<T, F>::unique_ptr2(unique_ptr2 && up) noexcept
{
	p = std::move(up.p);
	delFun = std::move(up.delFun);
	up.p = nullptr;
}

template <typename T, typename F>
unique_ptr2<T, F> & unique_ptr2<T, F>::operator=(unique_ptr2 && rhs)
{
	if(this != & rhs)
	{
		delFun(p);
		p = std::move(rhs.p);
		delFun = std::move(rhs.delFun);
		rhs.p = nullptr;
	}
	return *this;
}

template <typename T, typename F>
T * unique_ptr2<T, F>::release()
{
	T * tmp = p;
	p = nullptr;
	return tmp;
}

template <typename T, typename F>
void unique_ptr2<T, F>::reset(T * up)
{
	if(p != nullptr)
		delFun(p);
	p = up;
}

#endif
