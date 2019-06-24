#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

bool isShorter(const std::string &s1, const std::string &s2)
{
	return s1.size() < s2.size();
}

void elimDups(std::vector<std::string> &words)
{
	std::sort(words.begin(), words.end());
	std::vector<std::string>::iterator ip = std::unique(words.begin(), words.end());
	words.erase(ip, words.end());
	
}

int main()
{
	std::vector<std::string> v1{"1","2","345","33","345"};
	elimDups(v1);
	std::stable_sort(v1.begin(), v1.end(), isShorter);
	
	for(const std::string &s : v1)
		std::cout << s << " ";
	std::cout << std::endl;
	
	return 0;
}
