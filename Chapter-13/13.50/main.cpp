#include<iostream>
#include<vector>
#include<utility>
#include "String.h"

int main()
{
	String s1("12345");
	String s = s1;
	s = s;
	s.push_back('6');
	s.push_back('7');
	s.resize(2);
	for(char * p = s.begin(); p != s.end(); ++p)
		std::cout << *p;
	std::cout << std::endl;
	
	std::vector<String> v;	
	std::cout << "-----" << std::endl;
	v.push_back(s1);
	std::cout << std::endl;
	v.push_back("1234");
	std::cout << std::endl;
	v.push_back(s);
	std::cout << std::endl;
	for(String & i : v)
	{
		for(char * p = i.begin(); p != i.end(); ++p)
			std::cout << *p;
		std::cout << std::endl;
	}
	std::cout << std::endl;
	
	String s5(std::move(s1));
	for(char * p = s5.begin(); p != s5.end(); ++p)
		std::cout << *p;
	std::cout << std::endl;
	
	s = std::move(s5);
	for(char * p = s.begin(); p != s.end(); ++p)
		std::cout << *p;
	std::cout << std::endl;
	
	return 0;
}



