#include<iostream>
#include<algorithm>
#include<list>
#include<string>

void elimDups(std::list<std::string> &words)
{
	words.sort();
	words.unique(); 
}

int main()
{
	std::list<std::string> words{"123","234","12","246","123","456","246","1","234"};
	elimDups(words);
	for(const std::string &word : words)
		std::cout << word << " ";
	std::cout << std::endl;
	return 0;
} 

