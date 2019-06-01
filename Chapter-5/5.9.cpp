#include<iostream>
 
int main()
{
	char c;
	int cnt = 0;
	while(std::cin >> c)
	{
		if(c == 'a')
			cnt++;
		if(c == 'e')
			cnt++;		
		if(c == 'i')
			cnt++;
		if(c == 'o')
			cnt++;
		if(c == 'u')
			cnt++;
	}
	
	std::cout << cnt << std::endl; 
	return 0;
}

