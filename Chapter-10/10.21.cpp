#include<iostream>

int main()
{
	int i = 5;
	auto lfun = [&i]() -> bool {if(i <= 0) return true; --i; return false; };
	
	while(!lfun())
		std::cout << i << " ";
	std::cout << std::endl;
	return 0;
}


