#include<iostream>
#include<cstddef>
int main()
{
	int arr[10];
	for(size_t i = 0; i < 10; i++)
		arr[i] = i;
		
	int arr2[10];
	for(size_t i = 0; i < 10; i++)
		arr2[i] = arr[i];
		
	for(size_t i = 0; i < 10; i++)
		std::cout << arr2[i] << " ";
	
	return 0;
}
