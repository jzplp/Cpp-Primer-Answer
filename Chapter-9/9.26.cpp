#include<iostream>
#include<vector>
#include<list> 
#include<iterator>

int main()
{
	int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
	
	std::vector<int> v(std::begin(ia), std::end(ia));
	std::list<int> l(std::begin(ia), std::end(ia));
	
	for(std::vector<int>::iterator vp = v.begin() ; vp != v.end(); )
	{
		if(*vp % 2 == 1)
			vp = v.erase(vp);
		else
			++vp;
	}
	for(std::list<int>::iterator lp = l.begin() ; lp != l.end(); )
	{
		if(*lp % 2 == 0)
			lp = l.erase(lp);
		else
			++lp;
	}
	
	for(int i : v)
		std::cout << i << " ";
	std::cout << std::endl;
	for(int i : l)
		std::cout << i << " ";
	std::cout << std::endl;
	return 0;
}
