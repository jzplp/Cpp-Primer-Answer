#include<iostream>
#include<string> 

class Employee
{
public:
	Employee() : number(++gen) { }
	Employee(const std::string & s) : name(s), number(++gen) { }
	std::ostream & show(std::ostream & os);
	Employee(const Employee & e) = delete;
	Employee & operator=(const Employee & e) = delete;
	~Employee() = default; 
private:
	std::string name;
	int number;
	static int gen;
};

std::ostream & Employee::show(std::ostream & os)
{
	os << name << " " << number;
	return os;
}

int Employee::gen = 0;

int main()
{
	Employee e("qwer"),e2;
	Employee e1("qazxsw");
	e.show(std::cout) << std::endl;
	e1.show(std::cout) << std::endl;
	e2.show(std::cout) << std::endl;
	return 0;
}
