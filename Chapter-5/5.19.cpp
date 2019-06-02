#include<iostream>
#include<string>

int main()
{
	std::string s1,s2;
	
	std::cout << "input two string: ";
	std::cin >> s1 >> s2;
	do
	{
		if(s1.size() > s2.size())
			std::cout << s2 << std::endl;
		else
			std::cout << s1 << std::endl;
		std::cout << "input two string: ";
	}while(std::cin >> s1 >> s2);
	
	return 0;
}

