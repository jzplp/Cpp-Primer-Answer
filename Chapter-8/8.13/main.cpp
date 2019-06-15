#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<vector>
#include<cstring>
#include "PersonInfo.h"

bool valid(const std::string &s)
{
	for(char c : s)
		if(!isdigit(c))
			return false;
	return true;
		 
} 

std::string format(std::string s)
{
	return s; 
} 

int main(int argc, char *argv[])
{
	if(argc < 3)
	{
		std::cerr << "No file!" << std::endl;
		return -1;
	}
	
	std::ifstream ifile(argv[1]);
	
	std::string line, word;
	std::vector<PersonInfo> people;
	while(getline(ifile, line))
	{
		PersonInfo info;
		std::istringstream record(line);
		record >> info.name;
		while(record >> word)
			info.phones.push_back(word);
		people.push_back(info); 
	}
	
	std::ofstream os(argv[2]);
	
	for(const PersonInfo &entry : people)
	{
		std::ostringstream formatted, badNums;
		for(const std::string &num : entry.phones)
		{
			if(!valid(num))
				badNums << " " << num;
			else
				formatted << " " << format(num);
		}
		if(badNums.str().empty())
			os << entry.name << formatted.str() << std::endl;
		else
			std::cerr << "input Error: " << entry.name << " invalid number(s) " << badNums.str() << std::endl; 
	}
	return 0;
} 

