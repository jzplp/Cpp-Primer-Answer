#include<string>
#include<iostream> 
#include<vector>
#include<algorithm>
#include "HasPtr.h"

int main()
{
	std::vector<HasPtr> hs{HasPtr("a789a"), HasPtr("a456a"), HasPtr("a123a"), HasPtr("a103a"), HasPtr("a699a"), HasPtr("a299a"), HasPtr("a999a"), HasPtr("a991a")};
	std::string s("a123a");
	for(int i = 0; i < 10; ++i)
	{
		s[1] = '0' + i;
		hs.push_back(s); 
	}
	std::sort(hs.begin(), hs.end());
	
	for(const HasPtr &ihs : hs)
		ihs.print(std::cout) << std::endl;
	
	std::cout << std::endl;
	
	HasPtr a("12345"), c("67890");
	a.print(std::cout) << std::endl;
	HasPtr b = a;
	b.print(std::cout) << std::endl;
	b = c;
	b.print(std::cout) << std::endl;
	swap(a,c);
	a.print(std::cout) << std::endl;
	c.print(std::cout) << std::endl;
	return 0;
}


