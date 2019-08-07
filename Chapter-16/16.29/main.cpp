#include <iostream>
#include <memory>
#include<vector>
#include "Blob.h"
#include "shared_ptr2.h"

int main()
{	
	Blob<int> b({1,2,3});
	b.push_back(4);
	b.push_back(5);
	b.pop_back();
	std::cout << b.empty() << " " << b.size() << " " << b.back() << " " << b.front() << " " << b[2] << std::endl;
	b = b;
	Blob<int> b2 = b;
	b = std::move(b);
	std::vector<int> v{12,3,4,45,5};
	Blob<int> bbb(v.begin(), v.end());
	for(int i =0; i < bbb.size(); ++i)
		std::cout << bbb[i] << " ";
	std::cout << std::endl;
 	return 0;
}


