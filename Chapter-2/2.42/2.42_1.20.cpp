#include<iostream> 
#include<string>
#include "Sales_data.h"

int main()
{
	Sales_data book;
	double price;
	std::cin >> book.ISBN >> book.amount >> price;
	book.totalPrice = price * book.amount;
	 
	std::cout << book.ISBN << ' ' << book.amount << ' ' << book.totalPrice;
	if(book.amount > 0)
		std::cout << ' ' << book.totalPrice / book.amount << std::endl;
	else
		std::cout  << ' ' << "No Sales!" << std::endl;
	return 0;
}
