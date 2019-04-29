#include<iostream>
int main()
{
	int v1,v2,temp;
	std::cin >> v1 >> v2;
	if(v1 > v2)
	{
		temp = v1;
		v1 = v2;
		v2 = temp;
	}
	while(v2 >= v1)
	{
		std::cout << v1 << " ";
		v1++;
	}
	std::cout << std::endl;
	return 0;
} 
