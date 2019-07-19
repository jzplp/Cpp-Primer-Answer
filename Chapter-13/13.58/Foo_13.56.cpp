#include<iostream>
#include<vector>
#include<algorithm>

class Foo
{
public:
	Foo sorted() &&;
	Foo sorted() const &;
	
private:
	std::vector<int> data;
};

Foo Foo::sorted() && 
{
	std::cout << "Foo sorted() &&" << std::endl;
	sort(data.begin(), data.end());
	return *this; 
}

Foo Foo::sorted() const &
{
	std::cout << "Foo sorted() const &" << std::endl;
	Foo ret(*this);
	return ret.sorted();
}

int main()
{
	Foo f1;
	f1.sorted();
	return 0; 
}
