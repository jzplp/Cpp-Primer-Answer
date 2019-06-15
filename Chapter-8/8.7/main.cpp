#include <fstream>
#include<iostream>
#include <string>
#include <exception>
#include <stdexcept>
#include "Sales_data.h"

int main(int argc, char *argv[])
{
	if(argc < 3)
	{
		std::cerr << "No Files!" <<std::endl;
		return -1;
	}
	
	std::ifstream in(argv[1]);
	std::ofstream out(argv[2], std::ofstream::app);
	
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
				print(out, total) << std::endl;
				total = trans;
			}
		}
		print(out, total) << std::endl;
	}
	else
	{
		std::cerr << "No data?!" <<std::endl;
		return -1;
	}

	return 0;
} 





