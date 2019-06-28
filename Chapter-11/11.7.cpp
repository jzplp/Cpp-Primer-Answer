#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<sstream>

int main()
{
	std::map<std::string, std::vector<std::string>> familys;
	
	std::string line;
	std::string name;
	
	while(std::getline(std::cin, line))
	{
		std::istringstream is(line); 
		is >> name;
		std::vector<std::string> &fam = familys[name];
		while(is >> name)
			fam.push_back(name);
	}
	
	for(const auto & pair : familys)
	{
		std::cout <<  pair.first << " ";
		for(const std::string &s : pair.second)
			std::cout << s << " "; 
		std::cout << std::endl;
	} 
	
	return 0;
} 

