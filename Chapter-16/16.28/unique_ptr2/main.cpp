#include<iostream>
#include<string>
#include<memory>

#include "unique_ptr2.h"
#include "DebugDelete.h"

template class unique_ptr2<int>; 

int main()
{
	unique_ptr2<int> up1(new int(3)), up2;
	std::cout << *up1 << " " << *(up1.get()) << std::endl;
	up2 = std::move(up1);
	std::cout << *up2 << " " << *(up2.get()) << std::endl;
	up2 = nullptr;
	up2.reset(new int(2));
	std::cout << *up2 << " " << *(up2.get()) << std::endl;
	//up2 = up2;
	unique_ptr2<std::string, DebugDelete> up3(new std::string("12345"), DebugDelete());
	std::cout << *up3 << " " << *(up3.get())  << " " <<  up3->size() << std::endl;
	
	return 0;
}

