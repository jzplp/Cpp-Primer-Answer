#include<iostream> 
#include<string>
#include "Sales_data.h"

int main()
{
	Sales_data total;
	double price;
	if(std::cin >> total.ISBN >> total.amount >> price)
	{
		total.totalPrice = price * total.amount;
		Sales_data trans;
		while (std::cin >> trans.ISBN >> trans.amount >> price)
		{
			trans.totalPrice = price * trans.amount;
			if(total.ISBN == trans.ISBN)
			{
				total.amount += trans.amount;
				total.totalPrice += trans.totalPrice;
			}
			else
			{
				std::cout << total.ISBN << ' ' << total.amount << ' ' << total.totalPrice;
				if(total.amount > 0)
					std::cout << ' ' << total.totalPrice / total.amount << std::endl;
				else
					std::cout  << ' ' << "No Sales!" << std::endl;
			total = trans;
			}
		}
		std::cout << total.ISBN << ' ' << total.amount << ' ' << total.totalPrice;
		if(total.amount > 0)
			std::cout << ' ' << total.totalPrice / total.amount << std::endl;
		else
			std::cout  << ' ' << "No Sales!" << std::endl;
	} else {
		std::cerr << "No data?!" << std::endl;
		return -1;
	}
	return 0;
}
