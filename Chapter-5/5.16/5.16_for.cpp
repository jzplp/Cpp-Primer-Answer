#include<iostream>
#include<vector>

int main()
{
	std::vector<int> v{1,2,3,4,5};
	for(std::vector<int>::size_type i = 0; i < v.size(); ++i)
	{
		std::cout << v[i] << " ";
	}
	std::cout << std::endl;
	
}

