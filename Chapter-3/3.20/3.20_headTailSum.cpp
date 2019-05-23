#include<iostream>
#include<vector>
#include<string>

int main()
{
	std::vector<int> v;
	int i;
	while(std::cin >> i)
		v.push_back(i);
	
	if(v.size() < 2)
		return -1;
	
	for(std::vector<int>::size_type j = 0; j < v.size()/2; ++j)
		std::cout << v[j] + v[v.size() - 1 - j] << " ";
	
	return 0;
}
