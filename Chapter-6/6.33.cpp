#include<iostream>
#include<vector>

void print(std::vector<int>::const_iterator it,std::vector<int>::const_iterator end)
{
	if(it != end)
	{
		std::cout << *it++ << " ";
		print(it, end);
	}
	return;
}
int main()
{
	std::vector<int> v{1,2,3,4,5};
	print(v.cbegin(), v.cend());
	
	return 0;
}


