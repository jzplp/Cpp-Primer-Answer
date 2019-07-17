#include<iostream>
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
	
	return 0;
}

