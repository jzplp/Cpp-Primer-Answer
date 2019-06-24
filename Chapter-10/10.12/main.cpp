#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include "Sales_data.h"

bool compareIsbn(const Sales_data &a, const Sales_data &b)
{
	return a.isbn() > a.isbn();
}

int main()
{
	std::vector<Sales_data> v;
	Sales_data sa;
	while(read(std::cin, sa))
		v.push_back(sa);
	
	std::sort(v.begin(), v.end(), compareIsbn);
	
	for(const Sales_data &a : v)
		print(std::cout, a) << std::endl;
	return 0;
}


