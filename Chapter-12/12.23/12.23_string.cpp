#include<iostream> 
#include<string>

int main()
{
	std::string str1 = "123";
	std::string str2 = "456";
	std::string * p = new std::string;
	
	*p += str1;
	*p += str2;
	std::cout << *p << std::endl; 
	
	return 0;
} 

