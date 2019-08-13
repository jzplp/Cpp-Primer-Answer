#include<iostream>
#include<string> 
#include<regex>

int main()
{
	std::string pattern("[^c]ei");
	//pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*";
	std::regex r(pattern);
	std::smatch result;
	std::string s;
	while(std::cin >> s)
	{
		if(std::regex_search(s, result, r))
			std::cout << result.str() << std::endl;
		else
			std::cout << "not found!" << std::endl;
	}
	return 0;
} 
