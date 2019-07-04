#include<iostream> 

int main()
{
	char * p = new char[20]{0};
	char c;
	int i = 0;
	while(std::cin >> c && i < 20)
		p[i++] = c;
	
	for(i = 0; i < 20; ++i)
		std::cout << p[i];
	std::cout << std::endl;
	return 0;
} 

