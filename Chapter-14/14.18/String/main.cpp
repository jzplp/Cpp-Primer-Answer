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
	std::cout << s << std::endl;
	
	std::vector<String> v;	v.push_back(s1);
	v.push_back("1234");
	v.push_back(s);
	for(String & i : v)
	{
		std::cout << i << std::endl;
	}
	
	String s5(std::move(s1));
	std::cout << s5 << std::endl;
	
	s = std::move(s5);
	std::cout << s << std::endl;
	
	std::cout << (s == s5) << " " <<  (s > s5) << " " <<  (s < s5) << " " <<  (s >= s5) << " " <<  (s <= s5) << std::endl;
	return 0;
}

