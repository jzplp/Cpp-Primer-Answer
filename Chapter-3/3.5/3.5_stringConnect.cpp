#include<iostream>
#include<string>

int main()
{
	std::string words,word1;
	while(std::cin >> word1)
		words += word1;
	std::cout << words;
	
	return 0;
}
