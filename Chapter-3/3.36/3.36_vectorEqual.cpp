#include<iostream>
#include<vector>
int main()
{
	std::vector<int> v1 = {1,2,3,4,5};
	std::vector<int> v2 = {1,2,3,4,6};
	
	if(v1 != v2)
		std::cout << "Not equal!" << std::endl;
	else
		std::cout << "Equal!" << std::endl;
	return 0;
}
