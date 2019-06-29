#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<sstream>
#include<utility>

int main()
{
	std::multimap<std::string, std::vector<std::pair<std::string, std::string>>> familys;
	
	std::string line;
	std::string fname, name, birth;
	std::pair<std::string, std::string> child;
	
	while(std::getline(std::cin, line))
	{
		std::istringstream is(line); 
		is >> fname;
		std::vector<std::pair<std::string, std::string>> fam;
		while(is >> name >> birth)
			fam.push_back({name, birth});
		familys.insert({fname, fam});
	}
	
	for(const std::pair<std::string, std::vector<std::pair<std::string, std::string>>> & p1 : familys)
	{
		std::cout <<  p1.first << std::endl;
		for(const std::pair<std::string, std::string> &p2 : p1.second)
			std::cout << p2.first << " " << p2.second << std::endl; 
		std::cout << std::endl;
	} 
	
	return 0;
} 



