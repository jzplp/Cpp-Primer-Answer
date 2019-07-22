#include<memory>
#include<vector>
#include<string>
#include<stdexcept>
#include "StrBlob.h"

StrBlob::StrBlob() : data(std::make_shared<std::vector<std::string>>()) { }

StrBlob::StrBlob(std::initializer_list<std::string> li) : data(std::make_shared<std::vector<std::string>>(li)) { }

StrBlob::StrBlob(const StrBlob &sb) : data(std::make_shared<std::vector<std::string>>(*(sb.data))) { }

std::string & StrBlob::operator[](std::size_t n)
{
	return (*data)[n];
}

const std::string & StrBlob::operator[](std::size_t n) const
{
	return (*data)[n];
}

std::string & StrBlobPtr::operator[](std::size_t n)
{
	return (*(wptr.lock()))[n + curr];
}
const std::string & StrBlobPtr::operator[](std::size_t n) const
{
	return (*(wptr.lock()))[n + curr];
}
const std::string & ConstStrBlobPtr::operator[](std::size_t n)
{
	return (*(wptr.lock()))[n + curr];
}
const std::string & ConstStrBlobPtr::operator[](std::size_t n) const
{
	return (*(wptr.lock()))[n + curr];
}

void StrBlob::push_back(std::string &&t)
{ 
	data->push_back(std::move(t));
}

StrBlob & StrBlob::operator=(const StrBlob &sb)
{
	data = std::make_shared<std::vector<std::string>>(*(sb.data));
	return *this;
}

void StrBlob::check(size_type i, const std::string & msg) const
{
	if(i >= data->size())
		throw std::out_of_range(msg);
}

void StrBlob::pop_back()
{
	check(0, "pop_back on empty StrBlob");
	data->pop_back();
}

const std::string & StrBlob::front() const
{
	check(0, "front on empty StrBlob");
	return data->front();
}

std::string & StrBlob::front()
{
	check(0, "front on empty StrBlob");
	return data->front();
}

const std::string & StrBlob::back() const
{
	check(0, "back on empty StrBlob");
	return data->back();
}

std::string & StrBlob::back()
{
	check(0, "back on empty StrBlob");
	return data->back();
}

StrBlobPtr StrBlob::begin()
{
	return StrBlobPtr(*this);
}

StrBlobPtr StrBlob::end()
{
	return StrBlobPtr(*this, data->size());
}

ConstStrBlobPtr StrBlob::cbegin() const
{
	return ConstStrBlobPtr(*this);
}

ConstStrBlobPtr StrBlob::cend() const
{
	return ConstStrBlobPtr(*this, data->size());
}

std::shared_ptr<std::vector<std::string>> StrBlobPtr::check(std::size_t i, const std::string & msg) const
{
	std::shared_ptr<std::vector<std::string>> ret = wptr.lock();
	if(!ret)
		throw std::runtime_error("unbound StrBlobPtr");
	if(i >= ret->size())
		throw std::out_of_range(msg);
	return ret;
}

std::string & StrBlobPtr::deref() const
{
	std::shared_ptr<std::vector<std::string>> p = check(curr, "dereference past end");
	return (*p)[curr];
}


StrBlobPtr & StrBlobPtr::add(StrBlob::size_type num)
{
	check(curr + num, "increment past end of StrBlobPtr");
	curr += num;
	return *this;
}

bool compare(const StrBlobPtr &p1, const StrBlobPtr &p2)
{
	if(p1.wptr.lock() == p2.wptr.lock() && p1.curr == p2.curr)
		return true;
	return false;
}

std::shared_ptr<std::vector<std::string>> ConstStrBlobPtr::check(std::size_t i, const std::string & msg) const
{
	std::shared_ptr<std::vector<std::string>> ret = wptr.lock();
	if(!ret)
		throw std::runtime_error("unbound ConstStrBlobPtr");
	if(i >= ret->size())
		throw std::out_of_range(msg);
	return ret;
}

std::string & ConstStrBlobPtr::deref() const
{
	std::shared_ptr<std::vector<std::string>> p = check(curr, "dereference past end");
	return (*p)[curr];
}

bool compare(const ConstStrBlobPtr &p1, const ConstStrBlobPtr &p2)
{
	if(p1.wptr.lock() == p2.wptr.lock() && p1.curr == p2.curr)
		return true;
	return false;
}

bool operator==(const StrBlob &lhs, const StrBlob &rhs)
{
	return *(lhs.data) == *(rhs.data);
}

bool operator==(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
	return (lhs.wptr.lock() == rhs.wptr.lock() && lhs.curr == rhs.curr);
}

bool operator==(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs)
{
	return (lhs.wptr.lock() == rhs.wptr.lock() && lhs.curr == rhs.curr);
}

bool operator!=(const StrBlob &lhs, const StrBlob &rhs)
{
	return !(lhs == rhs);
}

bool operator!=(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
	return !(lhs == rhs);
}

bool operator!=(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs)
{
	return !(lhs == rhs);
}

bool operator<(const StrBlob &lhs, const StrBlob &rhs)
{
	return *(lhs.data) < *(rhs.data);
}

bool operator<=(const StrBlob &lhs, const StrBlob &rhs)
{
	return !(lhs > rhs);
}

bool operator>(const StrBlob &lhs, const StrBlob &rhs)
{
	return *(lhs.data) > *(rhs.data);
}

bool operator>=(const StrBlob &lhs, const StrBlob &rhs)
{
	return !(lhs < rhs);
}

bool operator<(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
	return lhs.curr <  rhs.curr;
}
bool operator<=(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
	return !(lhs > rhs);
}
bool operator>(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
	return lhs.curr >  rhs.curr;
}
bool operator>=(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
	return !(lhs < rhs);
}

bool operator<(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs)
{
	return lhs.curr <  rhs.curr;
}

bool operator<=(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs)
{
	return !(lhs > rhs);
}

bool operator>(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs)
{
	return lhs.curr >  rhs.curr;
}

bool operator>=(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs)
{
	return !(lhs < rhs);
}

StrBlobPtr & StrBlobPtr::operator++()
{
	check(curr, "increment past end of StrBlobPtr");
	++curr;
	return *this;
}

StrBlobPtr & StrBlobPtr::operator--()
{
	--curr;
	check(curr, "decrement past begin of StrBlobPtr");
	return *this; 
}

StrBlobPtr StrBlobPtr::operator++(int)
{
	StrBlobPtr ret = *this;
	++*this;
	return ret; 
}
StrBlobPtr StrBlobPtr::operator--(int)
{
	StrBlobPtr ret = *this;
	--*this;
	return ret; 
}

ConstStrBlobPtr & ConstStrBlobPtr::operator++()
{
	check(curr, "increment past end of StrBlobPtr");
	++curr;
	return *this;
}

ConstStrBlobPtr & ConstStrBlobPtr::operator--()
{
	--curr;
	check(curr, "decrement past begin of StrBlobPtr");
	return *this; 
}

ConstStrBlobPtr ConstStrBlobPtr::operator++(int)
{
	ConstStrBlobPtr ret = *this;
	++*this;
	return ret; 
}

ConstStrBlobPtr ConstStrBlobPtr::operator--(int)
{
	ConstStrBlobPtr ret = *this;
	--*this;
	return ret; 
}

StrBlobPtr & StrBlobPtr::operator+=(int i)
{
	curr += i;
	return *this;
}

StrBlobPtr & StrBlobPtr::operator-=(int i)
{
	curr -= i;
	return *this;
}

ConstStrBlobPtr & ConstStrBlobPtr::operator+=(int i)
{
	curr += i;
	return *this;
}
ConstStrBlobPtr & ConstStrBlobPtr::operator-=(int i)
{
	curr -= i;
	return *this;
}

StrBlobPtr operator+(const StrBlobPtr &sbp, int i)
{
	StrBlobPtr ret = sbp;
	ret += i;
	return ret;
}

StrBlobPtr operator-(const StrBlobPtr &sbp, int i)
{
	StrBlobPtr ret = sbp;
	ret -= i;
	return ret;
}

ConstStrBlobPtr operator+(const ConstStrBlobPtr &sbp, int i)
{
	ConstStrBlobPtr ret = sbp;
	ret += i;
	return ret;
}

ConstStrBlobPtr operator-(const ConstStrBlobPtr &sbp, int i)
{
	ConstStrBlobPtr ret = sbp;
	ret -= i;
	return ret;
}

int operator-(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
	return lhs.curr - rhs.curr;
}

int operator-(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs)
{
	return lhs.curr - rhs.curr;
}
