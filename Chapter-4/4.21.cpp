#include<iostream>
#include<vector> 
int main()
{
	std::vector<int> v{1,2,3,4,5,6,7,8,9};
	for(int &i : v)
		if(i % 2 == 1)
			i *= 2;
	for(int i : v)
		std::cout << i << " ";
		 
	return 0;
}

