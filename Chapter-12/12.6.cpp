#include<iostream>
#include<vector> 

std::vector<int> * funPointer()
{
	return new std::vector<int>;
}

void input(std::istream &in, std::vector<int> * p)
{
	int i;
	while(in >> i)
		p->push_back(i);
}

void output(std::ostream &out, std::vector<int> * p)
{
	for(int i : *p)
		out << i << " ";
}
int main()
{
	std::vector<int> * p = funPointer();
	input(std::cin, p);
	output(std::cout, p);
	delete p;
	return 0;
} 




