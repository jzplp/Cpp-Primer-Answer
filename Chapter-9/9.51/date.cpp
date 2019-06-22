#include<string>
#include "date.h"
#include<iostream>
#include<vector>
#include<cstring>

date::date(std::string s)
{
	unsigned yeart = 0,montht = 0,dayt = 0;
	unsigned temp, temp2, temp3;
	std::string::size_type si,sitemp;
	static std::vector<std::string> Vmonth{"jan","feb","mar","apr","may","jun","jul","aug","sept","oct","nov","dec"};
	static std::string num("1234567890");
	for(char &c : s)
		c = tolower(c);
	for(std::string::size_type i = 0; i < Vmonth.size(); ++i)
	{
		if(s.find(Vmonth[i]) != std::string::npos)
			montht = i+1; 
	}
	if((si = s.find_first_of(num)) != std::string::npos)
	{
		s = s.substr(si);
		temp = stoi(s, &si);
		s = s.substr(si);
		if(temp > 31)
			yeart = temp;
		else if(montht == 0)
			montht = temp;
		else
			dayt = temp;
		if((si = s.find_first_of(num)) != std::string::npos)
		{
			s = s.substr(si);
			temp = stoi(s, &si);
			s = s.substr(si);
			if(temp > 31)
				yeart = temp;
			else if(montht == 0)
				montht = temp;
			else
				dayt = temp;
			if((si = s.find_first_of(num)) != std::string::npos)
			{
				s = s.substr(si);
				temp = stoi(s, &si);
				s = s.substr(si);
				if(temp > 31)
					yeart = temp;
				else if(montht == 0)
					montht = temp;
				else
					dayt = temp;
			}
		}
		
	}
	year = yeart;
	month =montht;
	day = dayt;
} 

std::ostream & date::show(std::ostream &os) const
{
	os << year << " " << month << " " << day;
	return os;
}
