#ifndef PERSON_H
#define PERSON_H

#include<iostream>
#include<string>

struct Person;

std::istream & read(std::istream & is, Person &p);

std::ostream & print(std::ostream & os, const Person &p);

class Person
{
public:
	Person() = default; 
	Person(const std::string &n) : name(n) { }
	Person(const std::string &n, const std::string &a) : name(n), address(a) { }
	Person(std::istream &is)
	{
		read(is, *this);
	}
	
	std::string getName() const
	{
		return name;
	}
	std::string getAddress() const
	{
		return address;
	}
private:
	std::string name;
	std::string address;
};

#endif

