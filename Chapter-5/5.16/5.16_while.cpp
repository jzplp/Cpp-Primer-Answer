#include<iostream>
#include<vector>

int main()
{
	std::vector<int> v{1,2,3,4,5};
	std::vector<int>::size_type i = 0;
	while(i < v.size())
	{
		std::cout << v[i] << " ";
		++i;
	}
	std::cout << std::endl;
	
}

