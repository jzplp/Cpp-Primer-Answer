#include<iostream> 
#include<string>
#include "Sales_data.h"
using std::cin;
using std::cout;
using std::endl;
using std::cerr;

int main()
{
	Sales_data total;
	double price;
	if(cin >> total.ISBN >> total.amount >> price)
	{
		total.totalPrice = price * total.amount;
		Sales_data trans;
		while (cin >> trans.ISBN >> trans.amount >> price)
		{
			trans.totalPrice = price * trans.amount;
			if(total.ISBN == trans.ISBN)
			{
				total.amount += trans.amount;
				total.totalPrice += trans.totalPrice;
			}
			else
			{
				cout << total.ISBN << ' ' << total.amount << ' ' << total.totalPrice;
				if(total.amount > 0)
					cout << ' ' << total.totalPrice / total.amount << endl;
				else
					cout  << ' ' << "No Sales!" << endl;
			total = trans;
			}
		}
		cout << total.ISBN << ' ' << total.amount << ' ' << total.totalPrice;
		if(total.amount > 0)
			cout << ' ' << total.totalPrice / total.amount << endl;
		else
			cout  << ' ' << "No Sales!" << endl;
	} else {
		cerr << "No data?!" << endl;
		return -1;
	}
	return 0;
}
