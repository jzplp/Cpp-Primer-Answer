#include<iostream>
#include<tuple>

int main()
{
	std::tuple<int, int, int> t{10, 20, 30};
	std::cout << std::get<0>(t) << " " << std::get<1>(t) << " " << std::get<2>(t);
	std::cout << std::endl; 
	return 0;
} 
