#ifndef STRBLOB_H
#define STRBLOB_H

#include<vector>
#include<string>
#include<initializer_list>
#include<memory>

class StrBlobPtr;

class StrBlob
{
	friend class StrBlobPtr;
public:
	typedef std::vector<std::string>::size_type size_type;
	
	StrBlob();
	StrBlob(std::initializer_list<std::string> li);
	
	inline size_type size() const { return data->size(); } 
	bool empty() const { return data->empty(); }
	void push_back(const std::string &t) { data->push_back(t); }
	void pop_back();
	
	const std::string & front() const;
	std::string & front();
	const std::string & back() const;
	std::string & back();
	
	StrBlobPtr begin();
	StrBlobPtr end();
private:
	std::shared_ptr<std::vector<std::string>> data;
	
	void check(size_type i, const std::string & msg) const;
}; 

class StrBlobPtr
{
	friend bool compare(StrBlobPtr &p1, StrBlobPtr &p2);
public:
	StrBlobPtr() : curr(0) { }
	StrBlobPtr(StrBlob &a, std::size_t sz = 0) : wptr(a.data), curr(sz) { }
	
	std::string & deref() const;
	StrBlobPtr & incr();
	
private:
	std::shared_ptr<std::vector<std::string>> check(std::size_t , const std::string &) const;
	std::weak_ptr<std::vector<std::string>> wptr;
	std::size_t curr;

};

#endif
