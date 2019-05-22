#include<iostream>
#include<string>

int main()
{
	std::string s1,s2;
	std::cin >> s1;
	for(char c : s1)
		if(!ispunct(c))
			s2 += c; 
	std::cout << s2; 
	
	return 0;
}
