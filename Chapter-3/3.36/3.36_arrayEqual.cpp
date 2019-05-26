#include<iostream>
#include<iterator>
int main()
{
	int arr1[5] = {1,2,3,4,5};
	int arr2[6] = {1,2,3,4,5};
	
	int *p1 = std::begin(arr1), *p2 = std::begin(arr2);
	for( ; p1 != std::end(arr1) && p2 != std::end(arr2); ++p1, ++p2)
		if(*p1 != *p2)
		{
			std::cout << "Not equal!" << std::endl;
			return 0;
		}
	if(p1 != std::end(arr1) || p2 != std::end(arr2))
	{
		std::cout << "Not equal!" << std::endl;
		return 0;
	}
	std::cout << "Equal!" << std::endl;
	return 0;
}
