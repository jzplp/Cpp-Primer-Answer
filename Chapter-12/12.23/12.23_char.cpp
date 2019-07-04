#include<iostream> 
#include<cstring>

int main()
{
	const char * str1 = "123";
	const char * str2 = "456";
	char * p = new char[10]{0};
	
	strcat(p, str1);
	strcat(p, str2);
	for(char * pp = p; pp != p+10; ++pp)
	std::cout << *pp; 
	
	return 0;
} 

