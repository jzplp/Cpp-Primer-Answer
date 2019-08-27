#include<iostream>
#include<cstdlib>
#include<new>

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

int main()
{
	int * p = new int(3);
	std::cout << *p << std::endl;
	delete p;
	return 0;
} 

