#include<iostream>
#include<sstream>
#include<string>

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
	std::string s("1 2 3 4\n 5 6 7 8 ");
	std::istringstream is(s);
	input(is);
	std::cout << std::endl;
	return 0;
} 

