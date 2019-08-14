#include<iostream>
#include<string> 
#include<regex>
#include<set> 

int main()
{
	std::string pattern("[^c]ei");
	pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*";
	std::regex r(pattern);
	std::smatch result;
	std::string s;
	std::set<std::string> setWord{"albeit", "neighbour", "being"};
	while(std::getline(std::cin ,s))
	{
		for(std::sregex_iterator it(s.begin(), s.end(), r), end; it != end; ++it)
		{
			if(setWord.find(it->str()) != setWord.end())
				continue;
			size_t pos = it->prefix().length();
			pos = pos > 40 ? pos - 40 : 0;
			std::cout << it->prefix().str().substr(pos) << std::endl;
			std::cout << " >>> " << it->str() << "<<<" << std::endl;
			std::cout << it->suffix().str().substr(0, 40) << std::endl;
		}
	}
	return 0;
} 

