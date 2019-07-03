#include<memory>
#include<vector>
#include<string>
#include<stdexcept>
#include "StrBlob.h"


StrBlob::StrBlob() : data(std::make_shared<std::vector<std::string>>()) { }

StrBlob::StrBlob(std::initializer_list<std::string> li): data(std::make_shared<std::vector<std::string>>(li)) { }

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

ConstStrBlobPtr StrBlob::cbegin()
{
	return ConstStrBlobPtr(*this);
}

ConstStrBlobPtr StrBlob::cend()
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

StrBlobPtr & StrBlobPtr::incr()
{
	check(curr, "increment past end of StrBlobPtr");
	++curr;
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
		throw std::runtime_error("unbound StrBlobPtr");
	if(i >= ret->size())
		throw std::out_of_range(msg);
	return ret;
}

std::string & ConstStrBlobPtr::deref() const
{
	std::shared_ptr<std::vector<std::string>> p = check(curr, "dereference past end");
	return (*p)[curr];
}

ConstStrBlobPtr & ConstStrBlobPtr::incr()
{
	check(curr, "increment past end of StrBlobPtr");
	++curr;
	return *this;
}

bool compare(const ConstStrBlobPtr &p1, const ConstStrBlobPtr &p2)
{
	if(p1.wptr.lock() == p2.wptr.lock() && p1.curr == p2.curr)
		return true;
	return false;
}
