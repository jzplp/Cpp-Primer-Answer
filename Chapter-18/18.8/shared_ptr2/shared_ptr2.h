#ifndef SHARED_PTR2_H
#define SHARED_PTR2_H

#include<functional>
#include<memory>
#include<stdexcept>

template <typename T> class shared_ptr2;

template <typename T>
void swap(shared_ptr2<T> & lhs, shared_ptr2<T> & rhs);

template <typename T>
class shared_ptr2
{
public:
	shared_ptr2() noexcept : p(nullptr), ip(nullptr), delFun(nullptr) { }
	shared_ptr2(T * tp, std::function<void (T *)> fp = nullptr) noexcept : p(tp), ip(new int(1)), delFun(fp) {  }
	~shared_ptr2() noexcept;
	shared_ptr2(const shared_ptr2 & sp, std::function<void (T *)> fp = nullptr) noexcept;
	shared_ptr2 & operator=(const shared_ptr2 &);
	shared_ptr2(shared_ptr2 && sp, std::function<void (T *)> fp = nullptr) noexcept;
	shared_ptr2 & operator=(shared_ptr2 &&);
	void swap(shared_ptr2 & sp);
	
	T * get() const { return p; };
	T & operator*() const;
	T * operator->() const;
	explicit operator bool() const;
	
	bool unique() const;
	int use_count() const;
	void reset(T * sptr = nullptr, std::function<void (T *)> fp = nullptr);
	
private:
	void destroy();
	
	T * p;
	int * ip;
	std::function<void (T *)> delFun;
}; 

template<typename T, typename ... Args>
shared_ptr2<T> make_shared2(Args && ... args)
{
	T * p = new T(std::forward<Args>(args)...);
	return shared_ptr2<T>(p);
}

template <typename T>
shared_ptr2<T>::~shared_ptr2() noexcept
{
	destroy();
}

template <typename T>
void shared_ptr2<T>::destroy()
{
	if(ip != nullptr && p != nullptr && --*ip == 0)
	{
		delFun ? delFun(p) : delete p;
		p = nullptr;
		delete ip;
		ip = nullptr;
		delFun = nullptr;
	}
}

template <typename T>
shared_ptr2<T>::shared_ptr2(const shared_ptr2 & sp, std::function<void (T *)> fp) noexcept : p(sp.p), ip(sp.ip)
{
	++*ip;
	if(fp == nullptr)
		delFun = sp.delFun;
	else
		delFun = fp;
}

template <typename T>
shared_ptr2<T> & shared_ptr2<T>::operator=(const shared_ptr2 & rhs)
{
	if(p != rhs.p)
	{
		destroy();
		p = rhs.p;
		ip = rhs.ip;
		delFun = rhs.delFun;
		++*ip;
	}
	return *this;
}

template <typename T>
shared_ptr2<T>::shared_ptr2(shared_ptr2 && sp, std::function<void (T *)> fp) noexcept : p(std::move(sp.p)), ip(std::move(sp.ip))
{
	if(fp == nullptr)
		delFun = sp.delFun;
	else
		delFun = fp;
	sp.p = nullptr;
	sp.ip =nullptr;
	sp.delFun = nullptr;
}

template <typename T>
shared_ptr2<T> & shared_ptr2<T>::operator=(shared_ptr2 && rhs)
{
	if(p != rhs.p)
	{
		destroy();
		p = std::move(rhs.p);
		ip = std::move(rhs.ip);
		delFun = std::move(rhs.delFun);
		rhs.p = nullptr;
		rhs.ip = nullptr;
		rhs.delFun =nullptr;
	}
	else if(this != &rhs)
		rhs.destroy();
	return *this;
}

template <typename T>
int shared_ptr2<T>::use_count() const
{
	if(ip != nullptr)
		return *ip;
	throw std::runtime_error("no count!");
}

template <typename T>
bool shared_ptr2<T>::unique() const
{
	if(use_count() == 1)
		return true;
	return false;
}

template <typename T>
T & shared_ptr2<T>::operator*() const
{
	if(p == nullptr)
		throw std::runtime_error("no object!");
	return *p;
}

template <typename T>
T * shared_ptr2<T>::operator->() const
{
	return & this->operator*();
}

template <typename T>
shared_ptr2<T>::operator bool() const
{
	if(p == nullptr)
		return false;
	return true;
}

template <typename T>
void swap(shared_ptr2<T> & lhs, shared_ptr2<T> & rhs)
{
	lhs.swap(rhs);
}

template <typename T>
void shared_ptr2<T>::swap(shared_ptr2 & sp)
{
	using std::swap;
	swap(p, sp.p);
	swap(ip, sp.ip);
	swap(delFun, sp.delFun);
}

template <typename T>
void shared_ptr2<T>::reset(T * sptr, std::function<void (T *)> fp)
{
	destroy();
	p = sptr;
	if(p != nullptr)
		ip = new int(1);
	delFun = fp;
}


#endif
