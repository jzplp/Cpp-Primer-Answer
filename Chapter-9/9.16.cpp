#include<iostream>
#include<vector>
#include<list>

bool comp(const std::vector<int> &v, const std::list<int> &l)
{
	if(v.size() != l.size())
		return false;
	std::list<int>::const_iterator lp = l.cbegin();
	for(std::vector<int>::const_iterator vp = v.cbegin(); vp != v.cend() && lp != l.cend(); vp++, lp++)
		if(*vp != *lp)
			return false;
	return true; 
}

int main()
{
	std::vector<int> v{1,2,3,4,5};
	std::list<int> l{1,2,3,4,5};
	
	std::cout << comp(v,l) << std::endl;
	
	return 0;
}
