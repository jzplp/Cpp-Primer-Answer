#include <iostream>
#include <memory>
#include "Blob.h"

int main()
{
	Blob<int> b({1,2,3});
	b.push_back(4);
	b.push_back(5);
	b.pop_back();
	for(BlobPtr<int> p = b.begin(); p != b.end(); ++p)
	{
		std::cout << *p << " ";
	}
	std::cout << std::endl;
	std::cout << b.empty() << " " << b.size() << " " << b.back() << " " << b.front() << " " << b[2] << std::endl;
	b = b;
	Blob<int> b2 = b;
	std::cout << (b == b2) << " " << (b.begin() > b.end()) << std::endl;
	b = std::move(b);
	
	for(ConstBlobPtr<int> p = b.cbegin(); p != b.cend(); ++p)
	{
		std::cout << *p << " " ;
	}
	std::cout << std::endl;
	ConstBlobPtr<int> p = b.cbegin();
	p++; --p;
	std::cout << *p << " " << *(p+1) << " " << (p < (p+1)) << " " << (p - p+2);
	std::cout << std::endl;
 	return 0;
}
