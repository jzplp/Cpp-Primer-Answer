#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<string>
#include<cstring>
#include<iterator>
#include<utility>

int main()
{
	std::unordered_map<std::string, size_t> word_count;
	std::string word;
	while(std::cin >> word)
	{
		for(char &c : word)
			c = tolower(c);
		std::string word_clean;
		std::copy_if(word.begin(), word.end(), std::back_inserter(word_clean), [](char c){ return isalpha(c); });
		if(word_clean == "")
			continue;
		std::pair<std::unordered_map<std::string, size_t>::iterator, bool> pib = word_count.insert({word_clean, 1});
		if(pib.second != true)
			++(pib.first->second); 
		
	}
	
	for(const auto &w : word_count)
		std::cout << w.first << " occurs " << w.second << ((w.second > 1) ? " times" : " time") << std::endl;
	return 0;
} 



