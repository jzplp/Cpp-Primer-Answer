#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include "PersonInfo.h"

int main()
{
	std::string line, word;
	std::vector<PersonInfo> people;
	while(getline(std::cin, line))
	{
		PersonInfo info;
		std::istringstream record(line);
		record >> info.name;
		while(record >> word)
			info.phones.push_back(word);
		people.push_back(info); 
	}
	
	for(const PersonInfo &p : people)
	{
		std::cout << p.name << " ";
		for(const std::string & s : p.phones)
			std::cout << s << " ";
		std::cout << std::endl;
	}
	return 0;
} 

