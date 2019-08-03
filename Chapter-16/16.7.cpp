#include<iostream>

template <typename T, unsigned U> constexpr
unsigned len(T (&arr)[U])
{
	return U;
}

int main()
{
	int arr1[4] = {1,2,3,4};
	double arr2[5] = {1,2,3,45,6};
	std::cout << len(arr1) << " " << len(arr2) << std::endl;
	return 0;
}
