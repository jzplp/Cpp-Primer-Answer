#include<iostream>
#include<vector>
#include<typeinfo>

int main()
{
	int a, * b;
	double c, *d;
	int arr[10];
	std::vector<int> v;
	
	std::cout << typeid(a).name() << " " 
	<< typeid(b).name() << " " 
	<< typeid(c).name() << " " 
	<< typeid(d).name() << " " 
	<< typeid(arr).name() << " " 
	<< typeid(v).name() << " "
	<< std::endl;
	return 0;
} 

