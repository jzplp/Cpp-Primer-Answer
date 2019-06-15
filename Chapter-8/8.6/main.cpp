#include <fstream>
#include<iostream>
#include <string>
#include <exception>
#include <stdexcept>
#include "Sales_data.h"

int main(int argc, char *argv[])
{
	if(argc < 2)
	{
		std::cerr << "No Files!" <<std::endl;
		return -1;
	}
	
	std::ifstream in(argv[1]);

	Sales_data total;
	if(read(in, total))
	{
		Sales_data trans;
		while(read(in, trans))
		{
			if(total.isbn() == trans.isbn())
				total.combine(trans);
			else
			{
				print(std::cout, total) << std::endl;
				total = trans;
			}
		}
		print(std::cout, total) << std::endl;
	}
	else
	{
		std::cerr << "No data?!" <<std::endl;
		return -1;
	}

	return 0;
} 





