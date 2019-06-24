#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

void elimDups(std::vector<std::string> &words)
{
	std::sort(words.begin(), words.end());
	std::vector<std::string>::iterator ip = std::unique(words.begin(), words.end());
	words.erase(ip, words.end());
	
}

int main()
{
	std::vector<std::string> v1{"1","2","3","4","5"};
	std::vector<std::string> v2{"1","1","3","3","5"};
	elimDups(v1);
	elimDups(v2);
	
	for(const std::string &s : v1)
		std::cout << s << " ";
	std::cout << std::endl;
	for(const std::string &s : v2)
		std::cout << s << " ";
	std::cout << std::endl;
	
	return 0;
}
