#include<iostream>
#include<string>
int main()
{
	std::string s1 = "12345";
	std::string s2 = "12346";
	
	std::cout << "s1 ";
	if(s1 == s2)
		std::cout << "=";
	else if(s1 > s2)
		std::cout << ">";
	else
		std::cout << "<";
	std::cout << " s2" << std::endl;
	return 0;
}
