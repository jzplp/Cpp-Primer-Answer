#include<iostream>
#include<string>

int main()
{
	std::string word1,word2;
	std::cin >> word1 >> word2;
	if(word1.size() == word2.size())
		std::cout << "string sizes are equal!" << std::endl;
	else
		std::cout << "string sizes are not equal!" << std::endl;
	if(word1.size() > word2.size())
		std::cout << word1 << std::endl;
	else
		std::cout << word2 << std::endl;
	
	return 0;
}
