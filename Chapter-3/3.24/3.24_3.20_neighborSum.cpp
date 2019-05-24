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
	
	for(std::vector<int>::const_iterator it = v.cbegin() + 1; it != v.cend(); ++it)
		std::cout << *it + *(it - 1) << " ";
	
	return 0;
}
