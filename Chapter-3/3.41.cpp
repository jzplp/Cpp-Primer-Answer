#include<iostream>
#include<vector>
#include<iterator> 

int main()
{
	int arr[] ={1,2,3,4,5};
	std::vector<int> v(std::begin(arr), std::end(arr));
	
	for(int i : v)
		std::cout << i << " ";

	return 0;
}
