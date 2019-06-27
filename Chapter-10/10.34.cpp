#include<iostream>
#include<vector>

int main()
{
	std::vector<int> v{1,2,3,4,5,6,7,8,9};
	
	for(std::vector<int>::const_reverse_iterator rp = v.crbegin(); rp != v.crend(); ++rp)
		std::cout << *rp << " ";
	std::cout << std::endl;
	 
	return 0;
} 

