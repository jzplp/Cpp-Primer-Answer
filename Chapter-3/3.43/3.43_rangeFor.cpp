#include<iostream>

int main()
{
	int ia[3][4] = {1,2,3,4,5,6,7,8,9,10,11,12};
	for(int (&row)[4] : ia)
		for(int col : row)
			std::cout << col << " "; 

	return 0;
}
