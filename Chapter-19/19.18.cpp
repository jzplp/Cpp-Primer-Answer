#include<iostream>
#include<vector>
#include<string>
#include<functional>
#include<algorithm>

int count(const std::vector<std::string> & v)
{
	return std::count_if(v.begin(), v.end(), std::mem_fn(&std::string::empty));
}

int main()
{
	std::vector<std::string> v{"1", "10"};
	v.push_back(std::string());
	v.push_back(std::string());
	v.push_back(std::string());
	
	std::cout << count(v) << std::endl;
	
	return 0;
} 

