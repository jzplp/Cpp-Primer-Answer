#include<iostream>
#include<forward_list>
#include<string> 

void findInsert(std::forward_list<std::string> &fl, const std::string &s1, const std::string &s2) 
{
	std::forward_list<std::string>::iterator flpr = fl.before_begin(), flpc = fl.begin();
	while(flpc != fl.end() && *flpc != s1)
		++flpc, ++flpr;
	if(flpc == fl.end())
		fl.insert_after(flpr, s2);
	else
		fl.insert_after(flpc, s2);
}

int main()
{
	std::forward_list<std::string> fl{"qw", "we", "er", "rt"};
	std::string s1 = "we1";
	std::string s2 = "123";
	findInsert(fl, s1, s2);
	
	for(const std::string &s : fl)
		std::cout << s << " ";
	std::cout << std::endl;
	
	return 0;
}
