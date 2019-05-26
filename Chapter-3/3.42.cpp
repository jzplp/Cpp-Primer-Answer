#include<iostream>
#include<vector>
#include<cstddef>

int main()
{
	int arr[5];
	std::vector<int> v{1,2,3,4,5};
	
	for(size_t i = 0; i < 5; ++i)
		arr[i] = v[i];
	
	for(int i : arr)
		std::cout << i << " ";

	return 0;
}
