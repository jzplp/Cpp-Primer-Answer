#include<iostream>
#include<string>

int main()
{
	std::string line;
	while(getline(std::cin, line))
	{
		std::cout << line << std::endl;
	}
	return 0;
}
