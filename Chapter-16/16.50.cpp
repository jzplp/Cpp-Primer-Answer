#include<iostream>
#include<string>

template <typename T>
void f(T t)
{
	std::cout << "void f(T t)" << std::endl;
}

template <typename T>
void f(const T * t)
{
	std::cout << "void f(const T * t)" << std::endl;
}

template <typename T>
void g(T t)
{
	std::cout << "void g(T t)" << std::endl;
}

template <typename T>
void g(T * t)
{
	std::cout << "void g(T * t)" << std::endl;
}

int main()
{
	int i = 42, *p = &i;
	const int ci = 0, *p2 = &ci;
	g(42); g(p); g(ci); g(p2);
	f(42); f(p); f(ci); f(p2);
	return 0;
}

