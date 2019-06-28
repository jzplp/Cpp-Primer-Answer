#include<iostream>
#include<algorithm>
#include<map>
#include<string>
#include<cstring>
#include<iterator>

int main()
{
	std::map<std::string, size_t> word_count;
	std::string word;
	while(std::cin >> word)
	{
		for(char &c : word)
			c = tolower(c);
		std::string word_clean;
		std::copy_if(word.begin(), word.end(), std::back_inserter(word_clean), [](char c){ return isalpha(c); });
		word_count[word_clean]++;
	}
	
	for(const auto &w : word_count)
		std::cout << w.first << " occurs " << w.second << ((w.second > 1) ? "times" : "time") << std::endl;
	return 0;
} 

