#include<iostream>
#include<vector>

std::vector<int>::const_iterator find(std::vector<int>::const_iterator cbeg,std::vector<int>::const_iterator cend, int val)
{
	while(cbeg != cend)
	{
		if(*cbeg == val)
			return cbeg;
		cbeg++;
	}
	return cend; 
}

int main()
{
	std::vector<int> v{1,2,3,4,5};
	if(find(v.cbegin(), v.cend(), 2) == v.cend())
		std::cout << "false";
	else
		std::cout << "true";
	std::cout << std::endl;
	return 0;
}
