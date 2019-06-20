#include<iostream>
#include<list>

int main()
{
	std::list<int> l{0,1,2,3,4,5,6,7,8,9};
	auto iter = l.begin();
	while(iter != l.end())
	{
		if(*iter % 2)
		{
			iter =l.insert(iter, *iter);
			iter++;
			iter++;
		}
		else
			iter = l.erase(iter);
	}
	
	for(int i : l)
		std::cout << i << " ";
	std::cout << std::endl; 
	
	return 0;
}
