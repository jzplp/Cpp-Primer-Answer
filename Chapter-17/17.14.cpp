#include<iostream>
#include<string> 
#include<regex>

int main()
{
	try
	{
		std::regex r;
		//r = "[z-a]";
		//r = "[a-b";
		//r = "(a";
		r = "**(a";
		//std::regex_match("abc", r);
		
	}catch(std::regex_error e)
	{
		std::cout << e.what() << " code:" << std::endl; 
	}
	return 0;
} 
