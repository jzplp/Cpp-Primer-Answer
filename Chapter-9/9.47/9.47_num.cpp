#include<iostream>
#include<string>

int main()
{
	std::string num("0123456789");
	std::string s("ab2c3d7R4E6");
	
	std::string::size_type i = 0;
	while(i != s.size())
	{
		i = s.find_first_of(num, i);
		if(i == std::string::npos)
			break;
		std::cout << i << " " << s[i] << std::endl;
		++i;
	}
	
	return 0;
}
