#ifndef STRBLOB_H
#define STRBLOB_H

#include<vector>
#include<string>
#include<initializer_list>
#include<memory>

class StrBlob
{
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

private:
	std::shared_ptr<std::vector<std::string>> data;
	
	void check(size_type i, const std::string & msg) const;
}; 


#endif
