#include<iostream>
#include<deque>
#include<list>

int main()
{
	std::list<int> l{1,2,3,4,5,6,7,8,9,10};
	std::deque<int> d1;
	std::deque<int> d2; 
	for(std::list<int>::const_iterator lp = l.cbegin(); lp != l.cend(); lp++)
	{
		if(*lp%2 == 0)
			d1.push_back(*lp);
		else
			d2.push_back(*lp);
	}
	for(std::deque<int>::size_type i = 0; i != d1.size(); ++i)
		std::cout << d1[i] << " ";
	std::cout << std::endl;
	for(std::deque<int>::size_type i = 0; i != d2.size(); ++i)
		std::cout << d2[i] << " ";	
	std::cout << std::endl;
	
	return 0;
}
