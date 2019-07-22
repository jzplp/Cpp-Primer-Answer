#ifndef STRBLOB_H
#define STRBLOB_H

#include<vector>
#include<string>
#include<initializer_list>
#include<utility>
#include<memory>

class StrBlobPtr;
class ConstStrBlobPtr;

class StrBlob
{
	friend class StrBlobPtr;
	friend class ConstStrBlobPtr;
	friend bool operator==(const StrBlob &lhs, const StrBlob &rhs);
	friend bool operator!=(const StrBlob &lhs, const StrBlob &rhs);
	friend bool operator<(const StrBlob &lhs, const StrBlob &rhs);
	friend bool operator<=(const StrBlob &lhs, const StrBlob &rhs);
	friend bool operator>(const StrBlob &lhs, const StrBlob &rhs);
	friend bool operator>=(const StrBlob &lhs, const StrBlob &rhs);	
public:
	typedef std::vector<std::string>::size_type size_type;
	
	StrBlob();
	StrBlob(std::initializer_list<std::string> li);
	StrBlob(const StrBlob &sb);
	StrBlob & operator=(const StrBlob &sb);
	
	std::string & operator[](std::size_t n);
	const std::string & operator[](std::size_t n) const;
	
	inline size_type size() const { return data->size(); } 
	bool empty() const { return data->empty(); }
	void push_back(const std::string &t) { data->push_back(t); }
	void push_back(std::string &&t); 
	void pop_back();
	
	const std::string & front() const;
	std::string & front();
	const std::string & back() const;
	std::string & back();
	
	StrBlobPtr begin();
	StrBlobPtr end();
	
	ConstStrBlobPtr cbegin() const;
	ConstStrBlobPtr cend() const;
private:
	std::shared_ptr<std::vector<std::string>> data;
	
	void check(size_type i, const std::string & msg) const;
}; 

class StrBlobPtr
{
	friend bool compare(const StrBlobPtr &p1, const StrBlobPtr &p2);
	friend bool operator==(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
	friend bool operator!=(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
	friend bool operator<(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
	friend bool operator<=(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
	friend bool operator>(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
	friend bool operator>=(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
public:
	StrBlobPtr() : curr(0) { }
	StrBlobPtr(StrBlob &a, std::size_t sz = 0) : wptr(a.data), curr(sz) { }
	
	std::string & operator[](std::size_t n);
	const std::string & operator[](std::size_t n) const;
	StrBlobPtr & operator++();
	StrBlobPtr & operator--();	
	StrBlobPtr operator++(int);
	StrBlobPtr operator--(int);	
		
	std::string & deref() const;
	StrBlobPtr & add(StrBlob::size_type num); 
	
private:
	std::shared_ptr<std::vector<std::string>> check(std::size_t , const std::string &) const;
	std::weak_ptr<std::vector<std::string>> wptr;
	std::size_t curr;

};

class ConstStrBlobPtr
{
	friend bool compare(const ConstStrBlobPtr &p1, const ConstStrBlobPtr &p2);
	friend bool operator==(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs);
	friend bool operator!=(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs);
	friend bool operator<(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs);
	friend bool operator<=(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs);
	friend bool operator>(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs);
	friend bool operator>=(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs);
public:
	ConstStrBlobPtr() : curr(0) { }
	ConstStrBlobPtr(const StrBlob &a, std::size_t sz = 0) : wptr(a.data), curr(sz) { }
	
	const std::string & operator[](std::size_t n);
	const std::string & operator[](std::size_t n) const;
	
	std::string & deref() const;
	ConstStrBlobPtr & operator++();
	ConstStrBlobPtr & operator--();	
	ConstStrBlobPtr operator++(int);
	ConstStrBlobPtr operator--(int);
	
private:
	std::shared_ptr<std::vector<std::string>> check(std::size_t , const std::string &) const;
	std::weak_ptr<std::vector<std::string>> wptr;
	std::size_t curr;
};

bool operator==(const StrBlob &lhs, const StrBlob &rhs);
bool operator==(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
bool operator==(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs);
bool operator!=(const StrBlob &lhs, const StrBlob &rhs);
bool operator!=(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
bool operator!=(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs);

bool operator<(const StrBlob &lhs, const StrBlob &rhs);
bool operator<=(const StrBlob &lhs, const StrBlob &rhs);
bool operator>(const StrBlob &lhs, const StrBlob &rhs);
bool operator>=(const StrBlob &lhs, const StrBlob &rhs);

bool operator<(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
bool operator<=(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
bool operator>(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
bool operator>=(const StrBlobPtr &lhs, const StrBlobPtr &rhs);

bool operator<(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs);
bool operator<=(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs);
bool operator>(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs);
bool operator>=(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs);
#endif
