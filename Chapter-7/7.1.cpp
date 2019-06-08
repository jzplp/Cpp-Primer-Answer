#include<iostream>
#include<string>

struct Sales_data
{
	std::string ISBN;
	double totalPrice;
	int amount;	
};

int main()
{
	Sales_data total;
	double price;
	if(std::cin >> total.ISBN >> total.amount >> price)
	{
		total.totalPrice = total.amount * price;
		Sales_data trans;
		while(std::cin >> trans.ISBN >> trans.amount >> price)
		{
			trans.totalPrice = trans.amount * price;
			if(total.ISBN == trans.ISBN)
			{
				total.amount += trans.amount;
				total.totalPrice += trans.totalPrice;
			}
			else
			{
				std::cout << total.ISBN << " " << total.amount << " " << total.totalPrice << " " << total.totalPrice/total.amount << std::endl;
				total = trans;
			}
		}
		std::cout << total.ISBN << " " << total.amount << " " << total.totalPrice << " " << total.totalPrice/total.amount << std::endl;
	}
	else
	{
		std::cerr << "No data?!" <<std::endl;
		return -1;
	}
	return 0;
} 
