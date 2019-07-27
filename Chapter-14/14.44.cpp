#include<iostream>
#include<functional>
#include<algorithm>
#include<map>
#include<string>
#include<sstream>

int add(int i, int j)
{
	return i + j;
}

struct divide
{
	int operator()(int denominator, int divisor)
	{
		return denominator / divisor;
	}
};


int main()
{
	auto mod = [](int i, int j){ return i % j; };
	
	std::map<std::string, std::function<int(int, int)>> binops =
	{
		{"+", add}, {"-", std::minus<int>()}, {"/", divide()}, {"*", [](int i, int j){ return i * j; }}, {"%", mod}
	};
	
	std::string line;
	while(std::cin >> line)
	{
		int i,j;
		char o;
		std::istringstream is(line);
		is >> i;
		is >> o;
		is >> j;
		std::string op{o};
		std::cout << binops[op](i, j) << std::endl; 
	}
	return 0;
}
