#include<iostream>
#include<vector>

int main()
{
	std::vector<int> v{1,2,3,4,5,6,7,8,9};
	
	for(std::vector<int>::const_iterator rp = v.cend() - 1; rp != v.cbegin(); --rp)
		std::cout << *rp << " ";
	if(v.size() != 0)
		std::cout << *(v.cbegin()) << std::endl;
	 
	return 0;
} 

