#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<utility>

int main()
{
	std::multimap<std::string, std::string> m{{"A","a"}, {"B","b"}, {"C","c"},{"B","bb"}};
	
	std::multimap<std::string, std::string>::iterator ip = m.find(std::string("B"));
	m.erase(ip);
	
	for(const std::pair<const std::string, std::string> &p : m)
		std::cout << p.first << " " << p.second << std::endl;
	
	return 0;
} 



