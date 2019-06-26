#include<string>
#include<vector>
#include<functional>
#include<algorithm>
#include<iostream>

bool check_size(const std::string &s, std::string::size_type sz)
{
	return s.size() < sz; 
}

int main()
{
	std::vector<int> v{1,2,3,4,6,7};
	std::string s("12345");
	std::vector<int>::iterator vp = std::find_if(v.begin(),v.end(), std::bind(check_size, s, std::placeholders::_1));
	std::cout << *vp << std::endl;
	return 0;
}
