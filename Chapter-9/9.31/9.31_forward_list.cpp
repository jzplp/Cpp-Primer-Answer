#include<iostream>
#include<forward_list>

int main()
{
	std::forward_list<int> fl{0,1,2,3,4,5,6,7,8,9};
	auto iter = fl.begin(), pr = fl.before_begin();
	while(iter != fl.end())
	{
		if(*iter % 2)
		{
			iter =fl.insert_after(iter, *iter);
			pr = iter;
			iter++;
		}
		else
		{
			iter = fl.erase_after(pr);
		}
	}
	
	for(int i : fl)
		std::cout << i << " ";
	std::cout << std::endl; 
	
	return 0;
}
