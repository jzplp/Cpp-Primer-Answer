#include<iostream>

template <typename T, unsigned U>
T * begin(T (&arr)[U])
{
	return &arr[0];
}

template <typename T, unsigned U>
T * end(T (&arr)[U])
{
	return &arr[U];
}

int main()
{
	int arr1[4] = {1,2,3,4};
	double arr2[5] = {1,2,3,45,6};
	for(int * p = begin(arr1); p != end(arr1); ++p)
		std::cout << *p << " ";
	std::cout << std::endl;
	for(double * p = begin(arr2); p != end(arr2); ++p)
		std::cout << *p << " ";
	std::cout << std::endl;
	return 0;
}
