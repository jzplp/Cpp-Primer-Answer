#include<iostream> 
#include<string>
#include "Sales_data.h"
using std::cin;
using std::cout;
using std::endl;
int main()
{
	Sales_data book;
	double price;
	cin >> book.ISBN >> book.amount >> price;
	book.totalPrice = price * book.amount;
	 
	cout << book.ISBN << ' ' << book.amount << ' ' << book.totalPrice;
	if(book.amount > 0)
		cout << ' ' << book.totalPrice / book.amount << endl;
	else
		cout  << ' ' << "No Sales!" << endl;
	return 0;
}
