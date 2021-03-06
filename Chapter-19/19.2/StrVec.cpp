#include<string>
#include<memory>
#include<utility>
#include<algorithm> 
#include<utility> 
#include<iostream>
#include "StrVec.h"

void *operator new(size_t size)
{
	if(void * mem = malloc(size))
		return mem;
	else
		throw std::bad_alloc(); 
}

void operator delete(void * mem) noexcept
{
	free(mem);
}

std::allocator<std::string> StrVec::alloc;

void StrVec::push_back(const std::string &s)
{
	chk_n_alloc();
	alloc.construct(first_free++, s);
}

void StrVec::push_back(std::string &&s)
{
	chk_n_alloc();
	alloc.construct(first_free++, std::move(s));
}

std::pair<std::string *, std::string *> StrVec::alloc_n_copy(const std::string *b, const std::string *e)
{
	std::string * data = alloc.allocate(e - b);
	return {data, std::uninitialized_copy(b, e, data)};
}

void StrVec::free()
{
	if(elements)
	{
		StrVec * th = this;
		std::for_each(elements, first_free, [](std::string &s){ alloc.destroy(&s); } );
		alloc.deallocate(elements, cap - elements);
	}
}

StrVec::StrVec(const StrVec & s)
{
	std::pair<std::string *, std::string *> newdata = alloc_n_copy(s.begin(), s.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
}

StrVec::~StrVec()
{
	free();
}

StrVec & StrVec::operator=(const StrVec & rhs)
{
	std::pair<std::string *, std::string *> data = alloc_n_copy(rhs.begin(), rhs.end());
	free();
	elements = data.first;
	first_free = cap = data.second;
	return *this; 
}

StrVec & StrVec::operator=(std::initializer_list<std::string> li)
{
	std::pair<std::string *, std::string *> data = alloc_n_copy(li.begin(), li.end());
	free();
	elements = data.first;
	first_free = cap = data.second;
	return *this; 
}

StrVec::StrVec(std::initializer_list<std::string> li)
{
	std::pair<std::string *, std::string *> newdata = alloc_n_copy(li.begin(), li.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
}

StrVec::StrVec(StrVec &&s) noexcept : elements(s.elements), first_free(s.first_free), cap(s.cap) 
{
	s.elements = s.first_free = s.cap = nullptr;
}

StrVec & StrVec::operator=(StrVec &&rhs) noexcept
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

void StrVec::reallocate()
{
	size_t newcapacity = size() ? 2 * size() : 1;
	reserve(newcapacity);
}

void StrVec::reserve(size_t n)
{
	if(n <= capacity())
		return;
	std::string * newdata = alloc.allocate(n);
	std::string * dest = newdata;
	std::string * elem = elements;
	for(size_t i = 0; i != size(); ++i)
		alloc.construct(dest++, std::move(*elem++));
	free();
	elements = newdata;
	first_free = dest;
	cap = elements + n;
}

void StrVec::resize(size_t n, const std::string &t)
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

bool operator==(const StrVec &lhs, const StrVec &rhs)
{
	if(lhs.size() != rhs.size())
		return false;
	for(const std::string *p1 = lhs.begin(), *p2 = rhs.begin(); p1 != lhs.end(); ++p1, ++p2)
		if(*p1 != *p2)
			return false;
	return true;
}

bool operator!=(const StrVec &lhs, const StrVec &rhs)
{
	return !(lhs == rhs);
}

bool operator<(const StrVec &lhs, const StrVec &rhs)
{
	const std::string *p1 = lhs.begin(), *p2 = rhs.begin();
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

bool operator<=(const StrVec &lhs, const StrVec &rhs)
{
		return !(lhs > rhs);
}

bool operator>(const StrVec &lhs, const StrVec &rhs)
{
	const std::string *p1 = lhs.begin(), *p2 = rhs.begin();
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

bool operator>=(const StrVec &lhs, const StrVec &rhs)
{
		return !(lhs < rhs);
}

std::string & StrVec::operator[](std::size_t n)
{
	return elements[n];
}

const std::string & StrVec::operator[](std::size_t n) const
{
	return elements[n];
}
