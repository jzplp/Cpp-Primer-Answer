#ifndef BLOB_H
#define BLOB_H

#include <vector>
#include <memory>
#include <initializer_list>
#include <string>
#include "shared_ptr2.h"

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
	
	Blob();
	Blob(std::initializer_list<T> il);
	template <typename It>
	Blob(It b, It e);
	Blob(const Blob & sb);
	Blob(Blob && sb);
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
	
private:
	shared_ptr2<std::vector<T>> data;
	void check(size_type i, const std::string &msg) const;
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
Blob<T>::Blob() : data(new std::vector<T>()) { }

template <typename T>
Blob<T>::Blob(std::initializer_list<T> il) : data(new std::vector<T>(il)) { }

template <typename T>
template <typename It>
Blob<T>::Blob(It b, It e) : data(new std::vector<T>(b, e)) { }

template <typename T>
Blob<T>::Blob(const Blob & sb) : data(new std::vector<T>(*(sb.data))) { }

template <typename T>
Blob<T>::Blob(Blob && sb) : data(std::move(sb.data)) { }

template <typename T>
Blob<T> & Blob<T>::operator=(const Blob & rhs)
{
	data = new std::vector<T>(*(rhs.data));
	return *this;
}

template <typename T>
Blob<T> & Blob<T>::operator=(Blob && rhs)
{
	data = std::move(rhs.data);
	return *this;
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

#endif 

