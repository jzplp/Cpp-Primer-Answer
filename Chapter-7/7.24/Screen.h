#ifndef SCREEN_H
#define SCREEN_H

#include<string>
#include<iostream>

class Screen
{
public:
	
	using pos = std::string::size_type;
	
	Screen() = default;
	Screen(pos l, pos r) : height(l), width(r), contents(l*r, ' ') { }
	Screen(pos l, pos r, char c) : height(l), width(r), contents(l*r, c) { }
	
	char get() const
	{
		return contents[cursor];
	}
	inline char get(pos l, pos r) const;
	Screen & move(pos l, pos r);
private: 
	
	pos cursor = 0;
	pos height = 0, width = 0;
	std::string contents;
	
};

inline char Screen::get(pos l, pos r) const
{
	return contents[l * width + r];
}

inline Screen & Screen::move(pos l, pos r)
{
	cursor = l * width + r;
	return *this;
}

#endif
