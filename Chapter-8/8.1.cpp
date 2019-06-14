
#include<iostream>

std::istream & input(std::istream & is)
{
	char c;
	while(is >> c)
		std::cout << c;
	is.clear();
	return is;
}

int main()
{
	input(std::cin);
	char c;
	std::cin >> c;
	std::cout << c;
	return 0;
} 





