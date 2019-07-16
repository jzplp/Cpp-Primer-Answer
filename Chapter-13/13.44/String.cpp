#include <memory>
#include<utility>
#include<algorithm> 
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

String::String(const String & s)
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

String::String(const char *ps)
{
	const char *p = ps;
	while(*p != '\0')
		++p;
	std::pair<char *, char *> newdata = alloc_n_copy(ps, p);
	elements = newdata.first;
	first_free = cap = newdata.second;
}

