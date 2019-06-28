#include<iostream>
#include<string>
#include<vector>
#include<algorithm>


int main()
{
	std::vector<std::string> v;
	std::string s; 
	while(std::cin >> s)
		v.push_back(s);
	std::sort(v.begin(), v.end());
	std::vector<std::string>::iterator ip = std::unique(v.begin(), v.end());
	v.erase(ip, v.end());
	
	for(const std::string &si : v)
		std::cout << si << " ";
	std::cout << std::endl;
	
	return 0;
} 

