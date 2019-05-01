#include<iostream>
int main()
{
	int v1,v2,i;
	std::cin >> v1 >> v2;
	if(v1 > v2)
	{
		i = v1;
		v1 = v2;
		v2 = i;
	}
	for(i = v1;i <= v2;i++)
		std::cout << i << " ";
	std::cout << std::endl;
	return 0;
} 
