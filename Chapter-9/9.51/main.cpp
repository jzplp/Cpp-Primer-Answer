#include<iostream>
#include<string>
#include<vector>
#include "date.h"

int main()
{
	std::vector<std::string> v{"1,2,1900","1900/1/2","1234,Jan,1", "Jan,1,2001","feb/30/1024","JUN/11/2019"}; 
	
	for(const std::string &s : v)
	{
		date d(s);
		std::cout << s << " ";
		d.show(std::cout) << std::endl;
	}
	
	return 0;
}

