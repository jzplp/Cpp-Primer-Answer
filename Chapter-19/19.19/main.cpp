#include<iostream>
#include<vector>
#include<algorithm>
#include "Sales_data.h"
 
std::vector<Sales_data>::const_iterator searchOne(const std::vector<Sales_data> & v, double d)
{
	return std::find_if(v.begin(), v.end(), [d](const Sales_data & s){ return (s.avg_price() > d); });
}

int main()
{
	std::vector<Sales_data> v;
	Sales_data a("123", 2, 3);
	v.push_back(a);
	v.push_back(Sales_data("234", 3, 5));
	
	std::cout << *searchOne(v, 4) << std::endl;
	
	return 0;
} 

