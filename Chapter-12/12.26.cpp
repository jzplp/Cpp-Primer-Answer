#include<iostream> 
#include<string>
#include<memory>

int main()
{
	std::allocator<std::string> alloc;
	std::string * p = alloc.allocate(10);
	std::string s;
	std::string * q = p;
	while(std::cin >> s)
		alloc.construct(q++,s);
	
	for(std::string * pp = p; pp != q; ++pp)
		std::cout << *pp << " ";
	std::cout << std::endl; 
	
	while(q != p)
		alloc.destroy(--q);
	alloc.deallocate(p, 10);
	
	return 0;	 
}
