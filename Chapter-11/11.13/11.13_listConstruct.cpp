#include<iostream>
#include<string>
#include<vector>
#include<utility>


int main()
{
	std::vector<std::pair<std::string, int>> v;
	std::string s;
	int n;
	while(std::cin >> s >> n)
		v.push_back({s, n});
	
	for(std::pair<std::string, int> p : v)
		std::cout << p.first << " " << p.second << std::endl;
	
	return 0;
} 

