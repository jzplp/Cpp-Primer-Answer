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
	
	for(std::vector<int>::size_type j = 1; j != v.size(); ++j)
		std::cout << v[j] + v[j - 1] << " ";
	
	return 0;
}
