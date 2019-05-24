#include<iostream>
#include<vector>

int main()
{
	std::vector<int> v;
	int i;
	while(std::cin >> i)
		v.push_back(i);
	
	if(v.size() < 2)
		return -1;
	
	for(std::vector<int>::const_iterator it = v.cbegin(); it != v.cbegin() + v.size()/2 ; ++it)
		std::cout << *it + *(v.cend() - 1 - (it - v.cbegin())) << " ";
	
	return 0;
}
