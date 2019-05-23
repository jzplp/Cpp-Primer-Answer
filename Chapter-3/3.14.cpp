#include<iostream>
#include<vector>

int main()
{
	std::vector<int> v;
	int i;
	while(std::cin >> i)
		v.push_back(i);
	for(int j : v)
		 std::cout << j << " ";
	return 0;
}
