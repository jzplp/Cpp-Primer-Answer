#include<iostream>
#include<algorithm>
#include<vector>
#include"Sales_item.h"
#include<iterator>
#include<string>

bool compareSales_item(const Sales_item &a, const Sales_item &b)
{
	return a.isbn() < b.isbn();
}

int main()
{
	std::istream_iterator<Sales_item> is(std::cin), eof;
	std::ostream_iterator<Sales_item> os(std::cout, "\n");
	std::vector<Sales_item> v(is, eof);
	std::sort(v.begin(), v.end(), compareSales_item);
	std::vector<Sales_item>::iterator vpb = v.begin(), vpm;
	Sales_item sum;
	while(vpb != v.end())
	{
		vpm = std::find_if(vpb, v.end(), [&vpb](const Sales_item &sa){ return sa.isbn() != vpb->isbn(); });
		sum = std::accumulate(vpb, vpm, Sales_item(vpb->isbn()));
		os = sum; 
		vpb = vpm;
	}

	return 0;
} 

