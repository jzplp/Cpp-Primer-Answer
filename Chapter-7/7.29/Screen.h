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
	
	char get() const { return contents[cursor]; }
	inline char get(pos l, pos r) const;
	
	inline Screen move(pos l, pos r);
	inline Screen set(char c);
	inline Screen set(pos l, pos r, char c);
	const Screen display(std::ostream &os) const { do_display(os); return *this; }
	Screen display(std::ostream &os) { do_display(os); return *this; }
	
private: 
	
	pos cursor = 0;
	pos height = 0, width = 0;
	std::string contents;
	
	void do_display(std::ostream &os) const { os << contents; }

};

inline char Screen::get(pos l, pos r) const
{
	return contents[l * width + r];
}

inline Screen Screen::move(pos l, pos r)
{
	cursor = l * width + r;
	return *this;
}


inline Screen Screen::set(char c)
{
	contents[cursor] = c;
	return *this;
}

inline Screen Screen::set(pos l, pos r, char c)
{
	contents[l * width + r] = c;
	return *this;
}


#endif
