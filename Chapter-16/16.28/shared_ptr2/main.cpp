#include<iostream>
#include<string>
#include<memory>

#include "shared_ptr2.h"
#include "DebugDelete.h"

template class shared_ptr2<int>; 

int main()
{
	shared_ptr2<int> sp(new int(3), DebugDelete()) ,sp1;;
	shared_ptr2<std::string> ssp(new std::string("12345"));
	std::cout << *sp << std::endl;
	std::cout << sp.unique() << " " << sp.use_count() << " " << *(sp.get()) << std::endl;
	std::cout << ssp.unique() << " " << ssp.use_count() << " " << *(ssp.get()) << std::endl;
	sp = sp;
	sp1 = sp;
	std::cout << sp1.unique() << " " << sp1.use_count() << " " << *(sp1.get()) << std::endl;
	sp1 = std::move(sp);
	std::cout << sp1.unique() << " " << sp1.use_count() << " " << *(sp1.get()) << std::endl;
	ssp.reset(new std::string("qwert"), DebugDelete());
	std::cout << ssp.unique() << " " << ssp.use_count() << " " << *(ssp.get()) << std::endl;
	
	return 0;
}
