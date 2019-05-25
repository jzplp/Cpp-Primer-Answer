#include<iostream>
#include<vector>

int main()
{
	std::vector<int> v;
	for(int i = 0; i < 10; i++)
		v.push_back(i);
	
	std::vector<int> v2;
	v2 = v;
	
	for(std::vector<int>::size_type i = 0; i < 10; i++)
		std::cout << v2[i] << " ";
	
	return 0;
}
