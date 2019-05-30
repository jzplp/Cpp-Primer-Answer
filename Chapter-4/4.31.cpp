#include<iostream>
#include<vector>

int main()
{
	std::vector<int> ivec{1,2,3,4,5};
	std::vector<int>::size_type cnt = ivec.size();
	for(std::vector<int>::size_type ix = 0; ix != ivec.size(); ix++, cnt--)
		ivec[ix] = cnt; 
	
	return 0;
}

