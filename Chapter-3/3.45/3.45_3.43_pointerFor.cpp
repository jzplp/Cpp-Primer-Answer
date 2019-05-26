#include<iostream>

int main()
{
	int ia[3][4] = {1,2,3,4,5,6,7,8,9,10,11,12};
	for(auto row = ia; row != ia + 3; ++row)
		for(auto col = *row; col != *row + 4; ++col)
			std::cout << *col << " "; 

	return 0;
}

