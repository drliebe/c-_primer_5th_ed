#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <initializer_list>
#include <exception>
#include <fstream>

template <typename T> class BlobPtr;
template <typename T> class Blob;
template <typename T> bool operator==(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs);
template <typename T> bool operator!=(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs);

template <typename T> 
class Blob
{
public:
	friend class BlobPtr<T>;
	typedef T value_type;
	typedef typename std::vector<T>::size_type size_type;
	Blob();
	Blob(std::initializer_list<T> il);
	size_type size() const {return data->size();}
	bool empty() const {return data->empty();}
	void push_back(const T &t) {data->push_back(t);}
	void push_back(T &&t) {data->push_back(std::move(t));}
	void pop_back();
	T& front();
	const T& front() const;
	T& back();
	const T& back() const;
	T& operator[](size_type i);
	const T& operator[](size_type i) const;
	BlobPtr<T> begin();
	BlobPtr<T> end();
private:
	std::shared_ptr<std::vector<T>> data;
	void check(size_type i, const std::string &msg) const;
};


template <typename T>
Blob<T>::Blob() : data(std::make_shared<std::vector<T>>()) { }


template <typename T>
Blob<T>::Blob(std::initializer_list<T> il) : data(std::make_shared<std::vector<T>>(il)) { }


template <typename T>
void Blob<T>::pop_back()
{
	check(0, "pop_back on empty Blob");
	data->pop_back();
}


template <typename T>
T& Blob<T>::front()
{
	check(0, "front on empty Blob");
	return data->front();
}


template <typename T>
const T& Blob<T>::front () const
{
	check(0, "front on empty Blob");
	return data->front();
}


template <typename T>
T& Blob<T>::back()
{
	check(0, "back on empty Blob");
	return data->back();
}


template <typename T>
const T& Blob<T>::back() const
{
	check(0, "back on empty Blob");
	return data->back();
}


template <typename T>
T& Blob<T>::operator[](size_type i)
{
	check(i, "subscript out of range");
	return (*data)[i];
}


template <typename T>
const T& Blob<T>::operator[](size_type i) const
{
	check(i, "subscript out of range");
	return (*data)[i];
}


template <typename T>
BlobPtr<T> Blob<T>::begin()
{
	check(0, "begin on empty Blob");
	return BlobPtr<T>(*this, 0);
}


template <typename T>
BlobPtr<T> Blob<T>::end()
{
	check(0, "end on empty Blob");
	return BlobPtr<T>(*this, this->size());
}

template <typename T>
void Blob<T>::check(size_type i, const std::string &msg) const
{
	if (i >= data->size())
		throw std::out_of_range(msg);
}





template <typename T> 
class BlobPtr
{
public:
	friend bool operator==<T>(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs);
	friend bool operator!=<T>(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs);
	BlobPtr() : curr(0) { }
	BlobPtr(Blob<T> &a, size_t sz = 0) : wptr(a.data), curr(sz) { }
	T& operator*() const 
	{ auto p = check(curr, "dereference past end"); 
	  return (*p)[curr];
	}
	BlobPtr& operator++();
	BlobPtr& operator--();
	BlobPtr& operator++(int);
	BlobPtr& operator--(int);
private:
	std::shared_ptr<std::vector<T>> check(std::size_t, const std::string&) const;
	std::weak_ptr<std::vector<T>> wptr;
	std::size_t curr;
};


template <typename T>
BlobPtr<T>& BlobPtr<T>::operator++()
{
	check(curr, "increment past end of BlobPtr<T>");
	++curr;
	return *this;
}


template <typename T>
BlobPtr<T>& BlobPtr<T>::operator--()
{
	check(0, "decrement on empty BlobPtr<T>");
	if (curr <= 0)
		throw std::out_of_range("decrement past beginning of BlobPtr<T>");
	--curr;
	return *this;
}


template <typename T>
BlobPtr<T>& BlobPtr<T>::operator++(int i)
{
	BlobPtr ret = *this;
	++*this;
	return ret;
}


template <typename T>
BlobPtr<T>& BlobPtr<T>::operator--(int i)
{
	BlobPtr ret = *this;
	--*this;
	return ret;
}


template <typename T>
std::shared_ptr<std::vector<T>> BlobPtr<T>::check(std::size_t i, const std::string &msg) const
{
	auto ret = wptr.lock();
	if (!ret)
		throw std::runtime_error("unbound BlobPtr<T>");
	if (i >= ret->size())
		throw std::out_of_range(msg);
	return ret;
}


template <typename T> 
bool operator==(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs)
{
	if (lhs.curr == rhs.curr)
		return true;
	
	return false;
}

template <typename T> 
bool operator!=(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs)
{
	return !(lhs==rhs);
}




int main()
{
	Blob<std::string> b1;
	std::ifstream ifs("text.txt");
	std::string line;

	while(getline(ifs, line))
	{
		b1.push_back(line);
	}

	
	for(BlobPtr<std::string> pb=b1.begin(); pb != b1.end(); ++pb)
	{
		std::cout << *pb << std::endl;
	}

	return 0;
}




