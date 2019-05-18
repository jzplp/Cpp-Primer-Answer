#include<iostream>
int main()
{
	int i = 0, &r = i;
	auto a = r;
	const int ci = i, &cr = ci;
	auto b = ci;
	auto c = cr;
	auto d = &i;
	auto e = &ci;
	const auto f = ci;
	auto &g = ci;
	const auto &j = 42;
	
	std::cout << "a:" << a << std::endl;
	std::cout << "b:" << b << std::endl;
	std::cout << "c:" << c << std::endl;
	std::cout << "d:" << d << std::endl;
	std::cout << "e:" << e << std::endl;
	std::cout << "g:" << g << std::endl;
	
	a = 42;
	b = 42;
	c = 42;
	//d = 42;
	//e = 42;
	//g = 42;
	
	std::cout << "a:" << a << std::endl;
	std::cout << "b:" << b << std::endl;
	std::cout << "c:" << c << std::endl;
	std::cout << "d:" << d << std::endl;
	std::cout << "e:" << e << std::endl;
	std::cout << "g:" << g << std::endl;
	
	return 0;
}
