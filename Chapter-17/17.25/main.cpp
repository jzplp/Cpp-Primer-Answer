#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<vector>
#include<cstring>
#include<regex> 
#include "PersonInfo.h"

bool valid(const std::smatch &m)
{
	if(m[1].matched)
		return m[3].matched && (m[4].matched == 0 || m[4].str() == " ");
	else
		return !m[3].matched && m[4].str() == m[6].str();
}

int main()
{
	
	std::string line, word;
	std::vector<PersonInfo> people;
	
	std::string phoneRe = "(\\()?(\\d{3})(\\))?[ ]*([-. ])?[ ]*(\\d{3})[ ]*([-. ])?[ ]*(\\d{4})";
	std::regex r(phoneRe);
	std::smatch m;
	
	while(std::getline(std::cin, line))
	{
		PersonInfo info;
		std::istringstream record(line);
		record >> info.name;
		word = "";
		std::getline(record, word);
		for(std::sregex_iterator it(word.begin(), word.end(), r), end_it; it != end_it; ++it)
		{
			if(!valid(*it))
				std::cout << "not valid: " << it->str() << std::endl;
			else
			{
				std::cout << "valid: " << it->str() << std::endl;
				info.phones.push_back(it->format("$2.$5.$7 ", std::regex_constants::format_no_copy));
			}
		}
		people.push_back(info); 
	}
	
	for(const PersonInfo &entry : people)
	{
		std::cout << entry.name << " ";
		if(!entry.phones.empty())
			std::cout << entry.phones[0];
		std::cout << std::endl;
	}
	return 0;
} 

