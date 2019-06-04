#include<iostream>
#include<string>
#include<cstring>

bool hasUpper(const std::string &s)
{
	for (char c : s)
		if(isupper(c))
			return false;
	return true;
}

void strToLower(std::string &s)
{
	for (char &c : s)
		c = tolower(c);
}
int main()
{
	std::string s("12345QWE");
	std::cout << hasUpper(s) << std::endl;
	strToLower(s);
	std::cout << s <<std::endl;
	
	return 0;
} 

