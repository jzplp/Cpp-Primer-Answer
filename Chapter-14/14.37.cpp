#include<iostream>
#include<vector>
#include<algorithm>

struct Comp
{
	Comp(int i = 0) : a(i) { }
	bool operator()(int b)
	{
		if(a == b)
			return true;
		return false;
	}
	int a;
}; 

int main()
{

	std::vector<int> v{1,2,3,4,21,3,2,1,3,42,1};
	std::replace_if(v.begin(), v.end(), Comp(3), 123);
	for(int i : v)
		std::cout << i << " ";
	std::cout << std::endl; 
	return 0;
}
