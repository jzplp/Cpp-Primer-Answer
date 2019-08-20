#ifndef BLOB_H
#define BLOB_H

#include <vector>
#include <memory>
#include <initializer_list>
#include <string>
#include <new>
#include <iostream>
#include <cstdlib>

template <typename T> class Blob;
template <typename T> class BlobPtr;
template <typename T> class ConstBlobPtr;

template <typename T>
bool operator==(const Blob<T> &, const Blob<T> &);

template <typename T>
bool operator!=(const Blob<T> &, const Blob<T> &);

template <typename T>
bool operator<(const Blob<T> &, const Blob<T> &);

template <typename T>
bool operator<=(const Blob<T> &, const Blob<T> &);

template <typename T>
bool operator>(const Blob<T> &, const Blob<T> &);

template <typename T>
bool operator>=(const Blob<T> &, const Blob<T> &);

void haneld_out_of_memory();

template <typename T>
class Blob
{
	friend class BlobPtr<T>;
	friend class ConstBlobPtr<T>;
	friend bool operator== <T>(const Blob<T> &, const Blob<T> &);
	friend bool operator< <T>(const Blob<T> &, const Blob<T> &);
	friend bool operator> <T>(const Blob<T> &, const Blob<T> &);

public:
	typedef T value_type;
	typedef typename std::vector<T>::size_type size_type;
	
	Blob() noexcept;
	Blob(std::initializer_list<T> il);
	template <typename It>
	Blob(It b, It e);
	Blob(const Blob & sb) noexcept;
	Blob(Blob && sb) noexcept;
	Blob & operator=(const Blob & rhs);
	Blob & operator=(Blob && rhs);
	
	T & back();
	const T & back() const;
	T & front();
	const T & front() const; 
	
	T & operator[](size_type i);
	const T & operator[](std::size_t) const; 
	
	size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }
	void push_back(const T &t) { data->push_back(t); }
	void push_back(T && t) { data->push_back(std::move(t)); }
	void pop_back();
	
	BlobPtr<T> begin();
	BlobPtr<T> end();
	
	ConstBlobPtr<T> begin() const;
	ConstBlobPtr<T> end() const;
	
	ConstBlobPtr<T> cbegin() const;
	ConstBlobPtr<T> cend() const;
	
private:
	std::shared_ptr<std::vector<T>> data;
	void check(size_type i, const std::string &msg) const;
};

template <typename T>
BlobPtr<T> operator+(const BlobPtr<T> & bp, int i);

template <typename T>
BlobPtr<T> operator-(const BlobPtr<T> & bp, int i);

template <typename T>
int operator-(const BlobPtr<T> & lhs, const BlobPtr<T> & rhs);

template <typename T>
bool operator==(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs);

template <typename T>
bool operator!=(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs);

template <typename T>
bool operator<(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs);

template <typename T>
bool operator>(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs);

template <typename T>
bool operator<=(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs);

template <typename T>
bool operator>=(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs);

template <typename T>
class BlobPtr
{
	friend BlobPtr<T> operator+ <T>(const BlobPtr<T> & bp, int i);
	friend BlobPtr<T> operator- <T>(const BlobPtr<T> & bp, int i);
	friend bool operator== <T>(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs);
	friend bool operator< <T>(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs);
	friend bool operator> <T>(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs);
	friend int operator- <T>(const BlobPtr<T> & lhs, const BlobPtr<T> & rhs);
public:
	BlobPtr() noexcept : curr(0) { }
	BlobPtr(Blob<T> &a, std::size_t sz = 0) try : wptr(a.data), curr(sz) { }
	catch(const std::bad_alloc & e) { haneld_out_of_memory(); }
	
	T & operator[](std::size_t n) const;
	T & operator*() const;
	T * operator->() const;
	
	BlobPtr & operator++();
	BlobPtr & operator--();
	BlobPtr operator++(int);
	BlobPtr operator--(int);
	BlobPtr & operator+=(int i);
	BlobPtr & operator-=(int i);
	
private:
	std::shared_ptr<std::vector<T>> check(std::size_t, const std::string &) const;
	std::weak_ptr<std::vector<T>> wptr;
	std::size_t curr;
};

template <typename T>
ConstBlobPtr<T> operator+(const ConstBlobPtr<T> & bp, int i);

template <typename T>
ConstBlobPtr<T> operator-(const ConstBlobPtr<T> & bp, int i);

template <typename T>
int operator-(const ConstBlobPtr<T> & lhs, const ConstBlobPtr<T> & rhs);

template <typename T>
bool operator==(const ConstBlobPtr<T> &lhs, const ConstBlobPtr<T> &rhs);

template <typename T>
bool operator!=(const ConstBlobPtr<T> &lhs, const ConstBlobPtr<T> &rhs);

template <typename T>
bool operator<(const ConstBlobPtr<T> &lhs, const ConstBlobPtr<T> &rhs);

template <typename T>
bool operator>(const ConstBlobPtr<T> &lhs, const ConstBlobPtr<T> &rhs);

template <typename T>
bool operator<=(const ConstBlobPtr<T> &lhs, const ConstBlobPtr<T> &rhs);

template <typename T>
bool operator>=(const ConstBlobPtr<T> &lhs, const ConstBlobPtr<T> &rhs);

template <typename T>
class ConstBlobPtr
{
	friend ConstBlobPtr<T> operator+ <T>(const ConstBlobPtr<T> & bp, int i);
	friend ConstBlobPtr<T> operator- <T>(const ConstBlobPtr<T> & bp, int i);
	friend bool operator== <T>(const ConstBlobPtr<T> &lhs, const ConstBlobPtr<T> &rhs);
	friend bool operator< <T>(const ConstBlobPtr<T> &lhs, const ConstBlobPtr<T> &rhs);
	friend bool operator> <T>(const ConstBlobPtr<T> &lhs, const ConstBlobPtr<T> &rhs);
	friend int operator- <T>(const ConstBlobPtr<T> & lhs, const ConstBlobPtr<T> & rhs);
public:
	ConstBlobPtr() noexcept : curr(0) { }
	ConstBlobPtr(const Blob<T> &a, std::size_t sz = 0) try : wptr(a.data), curr(sz) { }
	catch(const std::bad_alloc & e) { haneld_out_of_memory(); }
	
	const T & operator[](std::size_t n) const;
	const T & operator*() const;
	const T * operator->() const;
	
	ConstBlobPtr & operator++();
	ConstBlobPtr & operator--();
	ConstBlobPtr operator++(int);
	ConstBlobPtr operator--(int);
	ConstBlobPtr & operator+=(int i);
	ConstBlobPtr & operator-=(int i);
	
private:
	std::shared_ptr<std::vector<T>> check(std::size_t, const std::string &) const;
	std::weak_ptr<std::vector<T>> wptr;
	std::size_t curr;
};

template <typename T>
void Blob<T>::check(size_type i,const std::string &msg) const
{
	if(i >= data->size())
		throw std::out_of_range(msg);
}

template <typename T>
T & Blob<T>::back()
{
	check(0, "back on empty Blob");
	return data->back();
}

template <typename T>
const T & Blob<T>::back() const
{
	check(0, "back on empty Blob");
	return data->back();
}

template <typename T>
T & Blob<T>::front()
{
	check(0, "front on empty Blob");
	return data->front();
}

template <typename T>
const T & Blob<T>::front() const
{
	check(0, "front on empty Blob");
	return data->front();
}

template <typename T>
T & Blob<T>::operator[](size_type i)
{
	check(i, "subscript out of range");
	return (*data)[i];
}

template <typename T>
const T & Blob<T>::operator[](std::size_t i) const
{
	check(i, "subscript out of range");
	return (*data)[i];
}

template <typename T>
void Blob<T>::pop_back()
{
	check(0, "pop_back on empty Blob");
	data->pop_back();
}

template <typename T>
Blob<T>::Blob() noexcept : data(std::make_shared<std::vector<T>>()) { }

template <typename T>
Blob<T>::Blob(std::initializer_list<T> il) try : data(std::make_shared<std::vector<T>>(il)) { }
catch(const std::bad_alloc & e) 
{
	haneld_out_of_memory();
}

template <typename T>
template <typename It>
Blob<T>::Blob(It b, It e) try : data(std::make_shared<std::vector<T>>(b, e)) { }
catch(const std::bad_alloc & err) 
{
	haneld_out_of_memory();
}

template <typename T>
Blob<T>::Blob(const Blob & sb) noexcept : data(std::make_shared<std::vector<T>>(*(sb.data))) { }

template <typename T>
Blob<T>::Blob(Blob && sb) noexcept : data(std::move(sb.data)) { }

template <typename T>
Blob<T> & Blob<T>::operator=(const Blob & rhs)
{
	data = std::make_shared<std::vector<T>>(*(rhs.data));
	return *this;
}

template <typename T>
Blob<T> & Blob<T>::operator=(Blob && rhs)
{
	data = std::move(rhs.data);
	return *this;
}

template <typename T>
BlobPtr<T> Blob<T>::begin()
{
	return BlobPtr<T>(*this);
}

template <typename T>
BlobPtr<T> Blob<T>::end()
{
	return BlobPtr<T>(*this, data->size());
}

template <typename T>
ConstBlobPtr<T> Blob<T>::begin() const
{
	return ConstBlobPtr<T>(*this);
}

template <typename T>
ConstBlobPtr<T> Blob<T>::end() const
{
	return ConstBlobPtr<T>(*this, data->size());
}

template <typename T>
ConstBlobPtr<T> Blob<T>::cbegin() const
{
	return ConstBlobPtr<T>(*this);
}
template <typename T>
ConstBlobPtr<T> Blob<T>::cend() const
{
	return ConstBlobPtr<T>(*this, data->size());
}

template <typename T>
std::shared_ptr<std::vector<T>> BlobPtr<T>::check(std::size_t i, const std::string & msg) const
{
	
	std::shared_ptr<std::vector<T>> ret = wptr.lock();
	if(!ret)
		throw std::runtime_error("unbound BlobPtr");
	if(i >= ret->size())
		throw std::out_of_range(msg);
	return ret;
}

template <typename T>
T & BlobPtr<T>::operator*() const
{
	std::shared_ptr<std::vector<T>> p = check(curr, "dereference past end");
	return (*p)[curr];
}
template <typename T>
T * BlobPtr<T>::operator->() const
{
	return this->operator*();
}

template <typename T>
BlobPtr<T> BlobPtr<T>::operator++(int)
{
	BlobPtr ret = *this;
	++*this;
	return ret;
}

template <typename T>
BlobPtr<T> BlobPtr<T>::operator--(int)
{
	BlobPtr ret = *this;
	--*this;
	return ret;
}

template <typename T>
BlobPtr<T> & BlobPtr<T>::operator++()
{
	check(curr, "increment past end of BlobPtr");
	++curr;
	return *this;
}

template <typename T>
BlobPtr<T> & BlobPtr<T>::operator--()
{
	--curr;
	check(curr, "decrement past begin of BlobPtr");
	return *this;
}

template <typename T>
BlobPtr<T> & BlobPtr<T>::operator+=(int i)
{
	curr += i;
	return *this;
}

template <typename T>
BlobPtr<T> & BlobPtr<T>::operator-=(int i)
{
	curr -= i;
	return *this;
}

template <typename T>
BlobPtr<T> operator+(const BlobPtr<T> & bp, int i)
{
	BlobPtr<T> ret = bp;
	ret += i;
	return ret; 
}

template <typename T>
BlobPtr<T> operator-(const BlobPtr<T> & bp, int i)
{
	BlobPtr<T> ret = bp;
	ret -= i;
	return ret; 	
}

template <typename T>
int operator-(const BlobPtr<T> & lhs, const BlobPtr<T> & rhs)
{
	return lhs.curr - rhs.curr;
}

template <typename T>
T & BlobPtr<T>::operator[](std::size_t n) const
{
	std::shared_ptr<std::vector<T>> p = check(curr + n, "dereference past end");
	return (*p)[curr + n];
}

template <typename T>
std::shared_ptr<std::vector<T>> ConstBlobPtr<T>::check(std::size_t i, const std::string & msg) const
{
	
	std::shared_ptr<std::vector<T>> ret = wptr.lock();
	if(!ret)
		throw std::runtime_error("unbound BlobPtr");
	if(i >= ret->size())
		throw std::out_of_range(msg);
	return ret;
}

template <typename T>
const T & ConstBlobPtr<T>::operator*() const
{
	std::shared_ptr<std::vector<T>> p = check(curr, "dereference past end");
	return (*p)[curr];
}

template <typename T>
const T * ConstBlobPtr<T>::operator->() const
{
	return this->operator*();
}

template <typename T>
ConstBlobPtr<T> ConstBlobPtr<T>::operator++(int)
{
	ConstBlobPtr ret = *this;
	++*this;
	return ret;
}

template <typename T>
ConstBlobPtr<T> ConstBlobPtr<T>::operator--(int)
{
	ConstBlobPtr ret = *this;
	--*this;
	return ret;
}

template <typename T>
ConstBlobPtr<T> & ConstBlobPtr<T>::operator++()
{
	check(curr, "increment past end of BlobPtr");
	++curr;
	return *this;
}

template <typename T>
ConstBlobPtr<T> & ConstBlobPtr<T>::operator--()
{
	--curr;
	check(curr, "decrement past begin of BlobPtr");
	return *this;
}

template <typename T>
ConstBlobPtr<T> & ConstBlobPtr<T>::operator+=(int i)
{
	curr += i;
	return *this;
}

template <typename T>
ConstBlobPtr<T> & ConstBlobPtr<T>::operator-=(int i)
{
	curr -= i;
	return *this;
}

template <typename T>
ConstBlobPtr<T> operator+(const ConstBlobPtr<T> & bp, int i)
{
	ConstBlobPtr<T> ret = bp;
	ret += i;
	return ret; 
}

template <typename T>
ConstBlobPtr<T> operator-(const ConstBlobPtr<T> & bp, int i)
{
	ConstBlobPtr<T> ret = bp;
	ret -= i;
	return ret; 	
}

template <typename T>
int operator-(const ConstBlobPtr<T> & lhs, const ConstBlobPtr<T> & rhs)
{
	return lhs.curr - rhs.curr;
}

template <typename T>
const T & ConstBlobPtr<T>::operator[](std::size_t n) const
{
	std::shared_ptr<std::vector<T>> p = check(curr + n, "dereference past end");
	return (*p)[curr + n];
}

template <typename T>
bool operator==(const Blob<T> & lhs, const Blob<T> & rhs)
{
	return *(lhs.data) == *(rhs.data);
}

template <typename T>
bool operator!=(const Blob<T> & lhs, const Blob<T> & rhs)
{
	return !(lhs == rhs);
}

template <typename T>
bool operator<(const Blob<T> & lhs, const Blob<T> & rhs)
{
	return *(lhs.data) < *(rhs.data);
}

template <typename T>
bool operator<=(const Blob<T> & lhs, const Blob<T> & rhs)
{
	return !(lhs > rhs);
}

template <typename T>
bool operator>(const Blob<T> & lhs, const Blob<T> & rhs)
{
	return *(lhs.data) > *(rhs.data);
}

template <typename T>
bool operator>=(const Blob<T> & lhs, const Blob<T> & rhs)
{
	return !(lhs < rhs);
}

template <typename T>
bool operator==(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs)
{
	return lhs.curr == rhs.curr;
}

template <typename T>
bool operator!=(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs)
{
	return !(lhs == rhs);
}

template <typename T>
bool operator<(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs)
{
	return lhs.curr < rhs.curr;
}

template <typename T>
bool operator>(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs)
{
	return lhs.curr > rhs.curr;
} 

template <typename T>
bool operator<=(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs)
{
	return !(lhs > rhs);
}

template <typename T>
bool operator>=(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs)
{
	return !(lhs < rhs);
} 

template <typename T>
bool operator==(const ConstBlobPtr<T> &lhs, const ConstBlobPtr<T> &rhs)
{
	return lhs.curr == rhs.curr;
}

template <typename T>
bool operator!=(const ConstBlobPtr<T> &lhs, const ConstBlobPtr<T> &rhs)
{
	return !(lhs == rhs);
}

template <typename T>
bool operator<(const ConstBlobPtr<T> &lhs, const ConstBlobPtr<T> &rhs)
{
	return lhs.curr < rhs.curr;
}

template <typename T>
bool operator>(const ConstBlobPtr<T> &lhs, const ConstBlobPtr<T> &rhs)
{
	return lhs.curr > rhs.curr;
} 

template <typename T>
bool operator<=(const ConstBlobPtr<T> &lhs, const ConstBlobPtr<T> &rhs)
{
	return !(lhs > rhs);
}

template <typename T>
bool operator>=(const ConstBlobPtr<T> &lhs, const ConstBlobPtr<T> &rhs)
{
	return !(lhs < rhs);
} 

void haneld_out_of_memory()
{
	std::cerr << "ERROR: OUT_OF_MEMORY!" << std::endl;
	abort();
}

#endif 

