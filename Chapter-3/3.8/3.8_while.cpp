#include<iostream>
#include<string>

int main()
{
	std::string s;
	std::cin >> s;
	std::string::size_type i = 0;
	while(i < s.size())
	{
		s[i] = 'X';
		i++;
	}
	std::cout << s; 
	
	return 0;
}
