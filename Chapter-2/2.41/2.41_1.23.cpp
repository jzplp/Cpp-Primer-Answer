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
	Sales_data book1, book2;
	double price;
	int num = 0;
	if(!(std::cin >> book1.ISBN >> book1.amount >> price))
		return -1; 
	book1.totalPrice = price * book1.amount;
	num++;
	while (std::cin >> book2.ISBN >> book2.amount >> price)
	{
		book2.totalPrice = price * book2.amount;
		if(book1.ISBN == book2.ISBN)
		{
			book1.amount += book2.amount;
			book1.totalPrice += book2.totalPrice;
			num++;
		}
		else
		{
			std::cout << book1.ISBN << ' ' << book1.amount << ' ' << book1.totalPrice;
			if(book1.amount > 0)
				std::cout << ' ' << book1.totalPrice / book1.amount << std::endl;
			else
				std::cout  << ' ' << "No Sales!" << std::endl;
			std::cout << "num = " << num << std::endl; 
			num = 1;
			book1 = book2;
		}
	}
	std::cout << book1.ISBN << ' ' << book1.amount << ' ' << book1.totalPrice;
	if(book1.amount > 0)
		std::cout << ' ' << book1.totalPrice / book1.amount << std::endl;
	else
		std::cout  << ' ' << "No Sales!" << std::endl;
	std::cout << "num = " << num << std::endl; 
	return 0;
}
