#include<iostream>
#include<string>

int main()
{
	std::string s;
	std::cin >> s;
	
	for(std::string::size_type i = 0; i < s.size(); ++i)
		s[i] = 'X';
	std::cout << s; 
	
	return 0;
}
