#include<iostream>
#include<forward_list>

int main()
{
	std::forward_list<int> fl{1,2,3,4,5,6};
	for(std::forward_list<int>::iterator flpr = fl.before_begin(), flpc = fl.begin(); flpc != fl.end(); )
	{
		if(*flpc %2 == 1)
			flpc = fl.erase_after(flpr);
		else
		{
			flpr = flpc;
			flpc++;
		}
	}
	
	for(int i : fl)
		std::cout << i << " ";
	std::cout << std::endl;
	return 0;
}
