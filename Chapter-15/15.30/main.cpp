#include <iostream>
#include <memory>
#include "Quote.h"

int main()
{
	Basket b;
	b.add_item(Quote("qwe", 10));
	b.add_item(Quote("qwe", 10));
	b.add_item(Bulk_quote("wer", 20, 2, 0.2));
	b.add_item(Bulk_quote("wer", 20, 2, 0.2));
	b.add_item(Bulk_quote("wer", 20, 2, 0.2));
	b.add_item(Bulk_quote("ert", 20, 2, 0.2));
	b.add_item(Quote("rty", 10));
	b.total_receipt(std::cout);
	
	return 0;
} 

