#include<iostream>
#include<cstring>
int main()
{
	char s1[] = "12345";
	char s2[] = "12345";
	
	int value = strcmp(s1, s2);
	
	std::cout << "s1 ";
	if(value == 0)
		std::cout << "=";
	else if(value > 0)
		std::cout << ">";
	else
		std::cout << "<";
	std::cout << " s2" << std::endl;
	return 0;
}
