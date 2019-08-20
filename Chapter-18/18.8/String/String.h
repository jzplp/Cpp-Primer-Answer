#ifndef DEMO_STRING_H
#define DEMO_STRING_H

#include<memory>
#include<utility>
#include<iostream>

class String
{
	friend std::ostream & operator<<(std::ostream &os, const String & s);
	friend bool operator==(const String &lhs, const String &rhs);
	friend bool operator<(const String &lhs, const String &rhs);
	friend bool operator>(const String &lhs, const String &rhs);
public:
	String() noexcept : elements(nullptr), first_free(nullptr), cap(nullptr) { }	
	String(const char *) noexcept;
	~String() noexcept { free(); }
	String(const String &) noexcept;
	String & operator=(const String & rhs);
	
	String(String &&s) noexcept;
	String & operator=(String && rhs) noexcept;
	
	char & operator[](std::size_t n);
	const char & operator[](std::size_t n) const;
	
	void push_back(char c);
	size_t size() const { return first_free - elements; }
	size_t capacity() const { return cap - elements; } 
	char * begin() const { return elements; }
	char * end() const { return first_free; }
	
	void reserve(size_t n);
	void resize(size_t n, char c = '\0');
	
private:
	void chk_n_alloc();
	std::pair<char *, char *> alloc_n_copy(const char *, const char *);
	void free();
	void reallocate();
	
	static std::allocator<char> alloc;
	
	char * elements;
	char * first_free;
	char * cap;
	
};

std::ostream & operator<<(std::ostream &os, const String & s);
bool operator==(const String &lhs, const String &rhs);
bool operator!=(const String &lhs, const String &rhs);
bool operator<(const String &lhs, const String &rhs);
bool operator<=(const String &lhs, const String &rhs);
bool operator>(const String &lhs, const String &rhs);
bool operator>=(const String &lhs, const String &rhs);
#endif

