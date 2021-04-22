#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <memory>
#include <initializer_list>
#include <exception>


class StrBlobPtr;
class ConstStrBlobPtr;

class StrBlob {
public:
	friend class StrBlobPtr;
	friend class ConstStrBlobPtr;
	typedef std::vector<std::string>::size_type size_type;
	StrBlob();
	StrBlob(std::initializer_list<std::string> il);
	size_type size() const {return data->size();}
	bool empty() const {return data->empty();}
	void push_back(const std::string &t) {data->push_back(t);}
	void pop_back();
	std::string& front();
	const std::string& front() const;
	std::string& back();
	const std::string& back() const;
	StrBlobPtr begin();
	ConstStrBlobPtr cbegin() const;
	StrBlobPtr end();	
	ConstStrBlobPtr cend() const;

private:
	std::shared_ptr<std::vector<std::string>> data;
	void check(size_type i, const std::string &msg) const;

};

StrBlob::StrBlob() : data(std::make_shared<std::vector<std::string>>() ) {}

StrBlob::StrBlob(std::initializer_list<std::string> il) : data(std::make_shared<std::vector<std::string>>(il) ) {}

void StrBlob::check(StrBlob::size_type i, const std::string &msg) const
{
	if (i>=data->size())
		throw std::out_of_range(msg);
}

std::string& StrBlob::front()
{
	check(0, "front on empty StrBlob");
	return data->front();
}

const std::string& StrBlob::front() const
{
	check(0, "front on empty StrBlob");
	return data->front();
}

std::string& StrBlob::back()
{
	check(0, "back on empty StrBlob");
	return data->back();
}

const std::string& StrBlob::back() const
{
	check(0, "back on empty StrBlob");
	return data->back();
}

void StrBlob::pop_back()
{
	check(0, "pop_back on empty StrBlob");
	data->pop_back();
	return;
}



class StrBlobPtr
{
public:
	StrBlobPtr(): curr(0) {}
	StrBlobPtr(StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz) {}
	std::string &deref() const;
	StrBlobPtr &incr();
private:
	std::shared_ptr<std::vector<std::string>>
		check(std::size_t, const std::string &) const;
	std::weak_ptr<std::vector<std::string>> wptr;
	std::size_t curr;
};

std::string &StrBlobPtr::deref() const
{
	auto p = check(curr, "dereference past end");
	return (*p)[curr];
}

StrBlobPtr & StrBlobPtr::incr()
{
	check(curr, "increment past end of StrBlobPtr");
	++curr;
	return *this;
}

std::shared_ptr<std::vector<std::string>> StrBlobPtr::check(std::size_t i, const std::string &msg) const
{
	auto ret = wptr.lock();
	if (!ret)
		throw std::runtime_error("unbound StrBlobPtr");
	if (i>= ret->size())
		throw std::out_of_range(msg);
	return ret;
}


StrBlobPtr StrBlob::begin()
{
	return StrBlobPtr(*this);
}

StrBlobPtr StrBlob::end()
{
	return StrBlobPtr(*this, data->size());
}






class ConstStrBlobPtr
{
public:
	ConstStrBlobPtr(): curr(0) {}
	ConstStrBlobPtr(const StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz) {}
	std::string &deref() const;
	ConstStrBlobPtr &incr();
private:
	std::shared_ptr<std::vector<std::string>>
		check(std::size_t, const std::string &) const;
	std::weak_ptr<std::vector<std::string>> wptr;
	std::size_t curr;
};

std::string &ConstStrBlobPtr::deref() const
{
	auto p = check(curr, "dereference past end");
	return (*p)[curr];
}

ConstStrBlobPtr & ConstStrBlobPtr::incr()
{
	check(curr, "increment past end of ConstStrBlobPtr");
	++curr;
	return *this;
}

std::shared_ptr<std::vector<std::string>> ConstStrBlobPtr::check(std::size_t i, const std::string &msg) const
{
	auto ret = wptr.lock();
	if (!ret)
		throw std::runtime_error("unbound ConstStrBlobPtr");
	if (i>= ret->size())
		throw std::out_of_range(msg);
	return ret;
}



ConstStrBlobPtr StrBlob::cbegin() const
{
	return ConstStrBlobPtr(*this);
}

ConstStrBlobPtr StrBlob::cend() const
{
	return ConstStrBlobPtr(*this, data->size());
}



int main()
{
	const StrBlob s1({"One", "Two", "Three"});
	ConstStrBlobPtr cps1(s1);

	cps1.incr().incr();

	std::cout << cps1.deref() << std::endl;


	return 0;
}
