#include<iostream>
#include<iterator>
int main()
{
	int arr[5] = {1,2,3,4,5};
	for(int *p = std::begin(arr); p != std::end(arr); ++p)
		*p = 0;
	for(int a : arr)
		std::cout << a << " "; 
	return 0;
}
