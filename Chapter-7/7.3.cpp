#include<iostream>
#include<string>

struct Sales_data
{
	std::string ISBN;
	double totalPrice;
	int amount;
	
	std::string isbn() const
	{
		return ISBN;
	}
	Sales_data & combine(const Sales_data & sa);
};

Sales_data & Sales_data::combine(const Sales_data & sa)
{
	amount += sa.amount;
	totalPrice += sa.totalPrice;
	return *this;
}

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
			if(total.isbn() == trans.isbn())
				total.combine(trans);
			else
			{
				std::cout << total.isbn() << " " << total.amount << " " << total.totalPrice << " " << total.totalPrice/total.amount << std::endl;
				total = trans;
			}
		}
		std::cout << total.isbn() << " " << total.amount << " " << total.totalPrice << " " << total.totalPrice/total.amount << std::endl;
	}
	else
	{
		std::cerr << "No data?!" <<std::endl;
		return -1;
	}
	return 0;
} 
