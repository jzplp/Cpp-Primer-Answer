#include<iostream> 
#include<string>
#include "Sales_data.h"
using std::cin;
using std::cout;
using std::endl;

int main()
{
	Sales_data book1, book2;
	double price;
	int num = 0;
	if(!(cin >> book1.ISBN >> book1.amount >> price))
		return -1; 
	book1.totalPrice = price * book1.amount;
	num++;
	while (cin >> book2.ISBN >> book2.amount >> price)
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
			cout << book1.ISBN << ' ' << book1.amount << ' ' << book1.totalPrice;
			if(book1.amount > 0)
				cout << ' ' << book1.totalPrice / book1.amount << endl;
			else
				cout  << ' ' << "No Sales!" << endl;
			cout << "num = " << num << endl; 
			num = 1;
			book1 = book2;
		}
	}
	cout << book1.ISBN << ' ' << book1.amount << ' ' << book1.totalPrice;
	if(book1.amount > 0)
		cout << ' ' << book1.totalPrice / book1.amount << endl;
	else
		cout  << ' ' << "No Sales!" << endl;
	cout << "num = " << num << endl; 
	return 0;
}
