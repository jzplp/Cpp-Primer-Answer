#include<iostream>
#include<vector>

int main()
{
	std::vector<int> l{0,1,2,3,4,5,6,7,8,9};
	auto iter = l.begin();
	while(iter != l.end())
	{
		if(*iter % 2)
		{
			l.insert(iter, *iter);
			iter += 2;
		}
		else
			iter = l.erase(iter);
	}
	
	for(int i : l)
		std::cout << i << " ";
	std::cout << std::endl; 
	
	return 0;
}
