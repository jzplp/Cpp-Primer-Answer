#include<iostream>
#include<memory>
#include<vector> 

std::shared_ptr<std::vector<int>> funPointer()
{
	return std::make_shared<std::vector<int>>();
}

void input(std::istream &in, std::shared_ptr<std::vector<int>> p)
{
	int i;
	while(in >> i)
		p->push_back(i);
}

void output(std::ostream &out, std::shared_ptr<std::vector<int>> p)
{
	for(int i : *p)
		out << i << " ";
}
int main()
{
	std::shared_ptr<std::vector<int>> p = funPointer();
	input(std::cin, p);
	output(std::cout, p);
	return 0;
} 




