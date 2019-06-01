#include<iostream>
#include<cstring>
#include<string> 
int main()
{
	std::string word, preword, wordMax;
	int cnt = 0, cntMax = 0;
	while(std::cin >> word)
	{
		if(word == preword)
			++cnt;
		else
			cnt = 1;
		if(cnt > cntMax)
		{
			cntMax = cnt;
			wordMax = word;
		}
		preword = word;
	}
	
	std::cout << wordMax << " " << cntMax << std::endl;
	return 0;
	
}

