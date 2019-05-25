#include<iostream>
#include<cstddef>
int main()
{
	int arr[10];
	for(size_t i = 0; i < 10; i++)
		arr[i] = i;
	for(size_t i = 0; i < 10; i++)
		std::cout << arr[i] << " ";
	 
	return 0;
}
