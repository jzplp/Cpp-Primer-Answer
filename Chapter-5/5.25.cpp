#include<iostream>
#include<stdexcept>

int main()
{
	int i1,i2;
	while(std::cin >> i1 >> i2)
		try { 
			if(i2 == 0)
				throw std::runtime_error ("i2 is zero!");
			std::cout << i1/i2 << std::endl;
		}
		catch (std::runtime_error err)
		{
			std::cout << err.what() << std::endl;
			std::cout << "input Y to continue, N to exit." << std::endl;
			char c;
			std::cin >> c;
			if (!std::cin || toupper(c) == 'N')
				break;
		}
	return 0;
}

