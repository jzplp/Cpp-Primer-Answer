#include<iostream>
#include<string>

int main()
{
	std::string s;
	std::cin >> s; 
	for(char &c : s)
		c = 'X';
	std::cout << s; 
	
	return 0;
}
