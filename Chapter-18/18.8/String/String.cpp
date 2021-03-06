#include <memory>
#include<utility>
#include<algorithm> 
#include<iostream>
#include "String.h"

std::allocator<char> String::alloc;

void String::chk_n_alloc()
{
	if(size() == capacity())
		reallocate();
}

void String::push_back(char c)
{
	chk_n_alloc();
	alloc.construct(first_free++, c);
}

std::pair<char *, char *> String::alloc_n_copy(const char * b, const char * e)
{
	char * data = alloc.allocate(e - b);
	return {data, std::uninitialized_copy(b, e, data)};
}

void String::free()
{
	if(elements)
	{
		std::for_each(elements, first_free, [](char &c){ alloc.destroy(&c); });
		alloc.deallocate(elements, cap - elements);
	}
}

void String::reallocate()
{
	size_t newcapacity = size() ? 2 * size() : 1;
	reserve(newcapacity);
}

void String::reserve(size_t n)
{
	if(n <= capacity())
		return;
	char * newdata = alloc.allocate(n);
	char * dest = newdata;
	char * elem = elements;
	for(size_t i = 0;i != size(); ++i)
		alloc.construct(dest++, std::move(*elem++));
	free();
	elements = newdata;
	first_free = dest;
	cap = elements + n;
}

void String::resize(size_t n, char c)
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
		alloc.construct(first_free++, c);
}

String::String(const String & s) noexcept
{
	std::pair<char *, char *> newdata = alloc_n_copy(s.begin(), s.end());
	elements = newdata.first;
	first_free = cap = newdata.second; 
}

String & String::operator=(const String & rhs)
{
	std::pair<char *, char *> data = alloc_n_copy(rhs.begin(), rhs.end());
	free();
	elements = data.first;
	first_free = cap = data.second;
	return *this;
}

String::String(const char *ps) noexcept
{
	const char *p = ps;
	while(*p != '\0')
		++p;
	std::pair<char *, char *> newdata = alloc_n_copy(ps, p);
	elements = newdata.first;
	first_free = cap = newdata.second;
}

String::String(String &&s) noexcept : elements(s.elements), first_free(s.first_free), cap(s.cap) 
{
	s.elements = s.first_free = s.cap = nullptr;
}

String & String::operator=(String && rhs) noexcept
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

std::ostream & operator<<(std::ostream &os, const String & s)
{
	for(char *p = s.begin(); p != s.end(); ++p)
		os << *p;
	return os;
}

bool operator==(const String &lhs, const String &rhs)
{
	if(lhs.size() != rhs.size())
		return false;
	for(const char *p1 = lhs.begin(), *p2 = rhs.begin(); p1 != lhs.end(); ++p1, ++p2)
		if(*p1 != *p2)
			return false;
	return true; 
}

bool operator!=(const String &lhs, const String &rhs)
{
	return !(lhs == rhs);
}

bool operator<(const String &lhs, const String &rhs)
{
	const char *p1 = lhs.begin(), *p2 = rhs.begin();
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

bool operator<=(const String &lhs, const String &rhs)
{
		return !(lhs > rhs);
}

bool operator>(const String &lhs, const String &rhs)
{
	const char *p1 = lhs.begin(), *p2 = rhs.begin();
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

bool operator>=(const String &lhs, const String &rhs)
{
		return !(lhs < rhs);
}

char & String::operator[](std::size_t n)
{
	return elements[n];
}
const char & String::operator[](std::size_t n) const
{
	return elements[n];
}
