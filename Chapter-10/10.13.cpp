#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

bool compareSize(const std::string &s)
{
	return s.size() >= 5 ? true : false;
}

int main()
{
	std::vector<std::string> v{"12345", "1234", "123456", "123"};
	std::vector<std::string>::const_iterator vp = std::partition(v.begin(), v.end(), compareSize);
	
	for(std::vector<std::string>::const_iterator vi = v.cbegin(); vi != vp; vi++)
		std::cout << *vi << " ";
	std::cout << std::endl;
	
	return 0;
}


