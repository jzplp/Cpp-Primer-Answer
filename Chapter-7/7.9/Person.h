#ifndef PERSON_H
#define PERSON_H

#include<iostream>
#include<string>

struct Person
{
	std::string name;
	std::string address;
	
	std::string getName() const
	{
		return name;
	}
	std::string getAddress() const
	{
		return address;
	}
};

std::istream & read(std::istream & is, Person &p);

std::ostream & print(std::ostream & os, const Person &p);

#endif

