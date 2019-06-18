#include<iostream>
#include<vector>
#include<list>

void show(std::vector<std::string>::const_iterator cbeg,std::vector<std::string>::const_iterator cend)
{
	while(cbeg != cend)
		std::cout << *cbeg++ << " ";
	std::cout << std::endl;
}

int main()
{
	std::list<const char *> l{"123", "234", "345"};
	std::vector<std::string> v;
	
	v.assign(l.cbegin(), l.cend());
	
	show(v.cbegin(), v.cend());
	
	return 0;
}
