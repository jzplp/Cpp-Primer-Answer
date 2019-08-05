#ifndef VEC_H
#define VEC_H

#include<string>
#include<memory>
#include<utility>
#include<algorithm>
#include<initializer_list> 

template <typename T> class Vec;

template <typename T>
bool operator==(const Vec<T> &lhs, const Vec<T> &rhs);
template <typename T>
bool operator!=(const Vec<T> &lhs, const Vec<T> &rhs);
template <typename T>
bool operator<(const Vec<T> &lhs, const Vec<T> &rhs);
template <typename T>
bool operator<=(const Vec<T> &lhs, const Vec<T> &rhs);
template <typename T>
bool operator>(const Vec<T> &lhs, const Vec<T> &rhs);
template <typename T>
bool operator>=(const Vec<T> &lhs, const Vec<T> &rhs);

template <typename T>
class Vec 
{
	friend bool operator== <T>(const Vec<T> &lhs, const Vec<T> &rhs);
	friend bool operator< <T>(const Vec<T> &lhs, const Vec<T> &rhs);
	friend bool operator> <T>(const Vec<T> &lhs, const Vec<T> &rhs);
public:
	
	Vec() : elements(nullptr), first_free(nullptr), cap(nullptr) { }
	Vec(const Vec &);
	Vec & operator=(const Vec &);
	~Vec();
	Vec(std::initializer_list<T> li);
	
	Vec(Vec &&s) noexcept;
	Vec & operator=(Vec &&rhs) noexcept;
	Vec & operator=(std::initializer_list<T> li);
	
	T & operator[](std::size_t n);
	const T & operator[](std::size_t n) const;
	
	void push_back(const T &);
	void push_back(T &&);
	size_t size() const { return first_free - elements; }
	size_t capacity() const { return cap - elements; }
	T *begin() const { return elements; }
	T *end() const { return first_free; } 
	
	void reserve(size_t);
	void resize(size_t n, const T &t = T());
private:
	
	static std::allocator<T> alloc;
	void chk_n_alloc()
	{
		if(size() == capacity())
			reallocate();
	}
	std::pair<T *, T *> alloc_n_copy(const T *, const T *);
	void free();
	void reallocate();
	
	T * elements;
	T * first_free;
	T * cap;
};

template <typename T>
std::allocator<T> Vec<T>::alloc;

template <typename T>
void Vec<T>::push_back(const T &s)
{
	chk_n_alloc();
	alloc.construct(first_free++, s);
}

template <typename T>
void Vec<T>::push_back(T &&s)
{
	chk_n_alloc();
	alloc.construct(first_free++, std::move(s));
}

template <typename T>
std::pair<T *, T *> Vec<T>::alloc_n_copy(const T *b, const T *e)
{
	T * data = alloc.allocate(e - b);
	return {data, std::uninitialized_copy(b, e, data)};
}

template <typename T>
void Vec<T>::free()
{
	if(elements)
	{
		Vec * th = this;
		std::for_each(elements, first_free, [](T &s){ alloc.destroy(&s); } );
		alloc.deallocate(elements, cap - elements);
	}
}

template <typename T>
Vec<T>::Vec(const Vec & s)
{
	std::pair<T *, T *> newdata = alloc_n_copy(s.begin(), s.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
}

template <typename T>
Vec<T>::~Vec()
{
	free();
}

template <typename T>
Vec<T> & Vec<T>::operator=(const Vec & rhs)
{
	std::pair<T *, T *> data = alloc_n_copy(rhs.begin(), rhs.end());
	free();
	elements = data.first;
	first_free = cap = data.second;
	return *this; 
}

template <typename T>
Vec<T> & Vec<T>::operator=(std::initializer_list<T> li)
{
	std::pair<T *, T *> data = alloc_n_copy(li.begin(), li.end());
	free();
	elements = data.first;
	first_free = cap = data.second;
	return *this; 
}

template <typename T>
Vec<T>::Vec(std::initializer_list<T> li)
{
	std::pair<T *, T *> newdata = alloc_n_copy(li.begin(), li.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
}

template <typename T>
Vec<T>::Vec(Vec &&s) noexcept : elements(s.elements), first_free(s.first_free), cap(s.cap) 
{
	s.elements = s.first_free = s.cap = nullptr;
}

template <typename T>
Vec<T> & Vec<T>::operator=(Vec<T> &&rhs) noexcept
{
	if(this != &rhs)
	{
		free();
		elements = rhs.elements;
		first_free = rhs.first_free;
		cap = rhs.cap;
		rhs.elements = rhs.first_free = rhs.cap = nullptr;
	}
	return *this;
}

template <typename T>
void Vec<T>::reallocate()
{
	size_t newcapacity = size() ? 2 * size() : 1;
	reserve(newcapacity);
}

template <typename T>
void Vec<T>::reserve(size_t n)
{
	if(n <= capacity())
		return;
	T * newdata = alloc.allocate(n);
	T * dest = newdata;
	T * elem = elements;
	for(size_t i = 0; i != size(); ++i)
		alloc.construct(dest++, std::move(*elem++));
	free();
	elements = newdata;
	first_free = dest;
	cap = elements + n;
}

template <typename T>
void Vec<T>::resize(size_t n, const T &t)
{
	if(n == size())
		return;
	if(n < size())
	{
		while(size() != n)
			alloc.destroy(--first_free);
		return;
	}
	if(n > capacity())
		reserve(n);
	while(size() != n)
		alloc.construct(first_free++, t);
}

template <typename T>
bool operator==(const Vec<T> &lhs, const Vec<T> &rhs)
{
	if(lhs.size() != rhs.size())
		return false;
	for(const T *p1 = lhs.begin(), *p2 = rhs.begin(); p1 != lhs.end(); ++p1, ++p2)
		if(*p1 != *p2)
			return false;
	return true;
}

template <typename T>
bool operator!=(const Vec<T> &lhs, const Vec<T> &rhs)
{
	return !(lhs == rhs);
}

template <typename T>
bool operator<(const Vec<T> &lhs, const Vec<T> &rhs)
{
	const T *p1 = lhs.begin(), *p2 = rhs.begin();
	for( ; p1 != lhs.end() && p2 != rhs.end(); ++p1, ++p2)
	{
		if(*p1 < *p2)
			return true;
		if(*p1 > *p2)
			return false;
	}
	if(p1 != lhs.end() && p2 == rhs.end())
		return false;
	if(p1 == lhs.end() && p2 != rhs.end())
		return true;
	return false;
}

template <typename T>
bool operator<=(const Vec<T> &lhs, const Vec<T> &rhs)
{
		return !(lhs > rhs);
}

template <typename T>
bool operator>(const Vec<T> &lhs, const Vec<T> &rhs)
{
	const T *p1 = lhs.begin(), *p2 = rhs.begin();
	for( ; p1 != lhs.end() && p2 != rhs.end(); ++p1, ++p2)
	{
		if(*p1 > *p2)
			return true;
		if(*p1 < *p2)
			return false;
	}
	if(p1 != lhs.end() && p2 == rhs.end())
		return true;
	if(p1 == lhs.end() && p2 != rhs.end())
		return false;
	return false;
}

template <typename T>
bool operator>=(const Vec<T> &lhs, const Vec<T> &rhs)
{
		return !(lhs < rhs);
}

template <typename T>
T & Vec<T>::operator[](std::size_t n)
{
	return elements[n];
}

template <typename T>
const T & Vec<T>::operator[](std::size_t n) const
{
	return elements[n];
}

#endif
