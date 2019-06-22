#ifndef DATE_H
#define DATE_H

#include<string>
#include<iostream>

class date
{
public:
	
	date(std::string s);
	std::ostream & show(std::ostream &os) const;
	
private:

	unsigned year;
	unsigned month;
	unsigned day;
	
};

#endif
