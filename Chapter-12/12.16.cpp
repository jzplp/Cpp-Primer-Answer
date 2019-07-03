#include<memory>

int main()
{
	std::unique_ptr<int> p(new int(1));
	std::unique_ptr<int> p2;
	p2 = p;
	return 0;
} 
