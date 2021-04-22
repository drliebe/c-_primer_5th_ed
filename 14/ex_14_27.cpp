#include <iostream>
#include <string>
#include <fstream>
#include <memory>
#include <vector>
#include <map>
#include <set>
#include <sstream>
#include <initializer_list>
#include <exception>
#include <utility>

class StrBlobPtr;
class ConstStrBlobPtr;

class StrBlob {
public:
	friend class StrBlobPtr;
	friend class ConstStrBlobPtr;
	friend bool operator==(const StrBlob &lhs, const StrBlob &rhs);
	friend bool operator!=(const StrBlob &lhs, const StrBlob &rhs);
	friend bool operator<(const StrBlob &lhs, const StrBlob &rhs);
	friend bool operator>(const StrBlob &lhs, const StrBlob &rhs);
	typedef std::vector<std::string>::size_type size_type;
	StrBlob();
	StrBlob(std::initializer_list<std::string> il);
	StrBlob(const StrBlob &orig) : data(std::make_shared<std::vector<std::string>>(*orig.data)) {}
	StrBlob &operator=(const StrBlob &rhs);
	std::string &operator[](size_t n);
	size_type size() const {return data->size();}
	bool empty() const {return data->empty();}
	void push_back(const std::string &t) {data->push_back(t);}
	void push_back(std::string &&s) {data->push_back(std::move(s));}
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

StrBlob &StrBlob::operator=(const StrBlob &rhs)
{
	if (this != &rhs)
	{
		data = std::make_shared<std::vector<std::string>>(*rhs.data);
	}
	return *this;
}

std::string &StrBlob::operator[](size_t n)
{
	return (*data)[n];
}

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

bool operator==(const StrBlob &lhs, const StrBlob &rhs)
{
	return ( lhs.data == rhs.data );
}

bool operator!=(const StrBlob &lhs, const StrBlob &rhs)
{
	return !(lhs == rhs);
}

bool operator<(const StrBlob &lhs, const StrBlob &rhs)
{
	return (*(lhs.data) < *(rhs.data)); 
}

bool operator>(const StrBlob &lhs, const StrBlob &rhs)
{
	return (rhs < lhs);
}

class StrBlobPtr
{
public:
	friend bool operator==(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
	friend bool operator!=(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
	friend bool operator<(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
	friend bool operator>(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
	StrBlobPtr(): curr(0) {}
	StrBlobPtr(StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz) {}
	std::string &deref() const;
	StrBlobPtr &incr();
	std::string &operator[](size_t n);
	StrBlobPtr &operator++();
	StrBlobPtr &operator--();
	StrBlobPtr operator++(int);
	StrBlobPtr operator--(int);
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


std::string &StrBlobPtr::operator[](size_t n)
{
	auto p = check(n, "operator[]");
	return (*p)[n];

}

StrBlobPtr &StrBlobPtr::operator++()
{
	check(curr, "increment past end of StrBlobPtr");
	++curr;
	return *this;
}

StrBlobPtr &StrBlobPtr::operator--()
{
	--curr;
	check(curr, "decrement past beginning of StrBlobPtr");
	return *this;
}

StrBlobPtr StrBlobPtr::operator++(int)
{
	StrBlobPtr temp = *this;
	++*this;
	return temp;
}

StrBlobPtr StrBlobPtr::operator--(int)
{
	StrBlobPtr temp = *this;
	--*this;
	return temp;
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


bool operator==(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
	return (lhs.check(lhs.curr,"Error in ==") == rhs.check(rhs.curr,"Error in ==")) && (lhs.curr == rhs.curr );
}

bool operator!=(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
	return !(lhs == rhs);
}

bool operator<(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
	return *(lhs.check(lhs.curr,"Error in <")) < *(rhs.check(rhs.curr,"Error in <"));	
}

bool operator>(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
	return (rhs < lhs);
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


class QueryResult;
class TextQuery
{
public:
	using line_no = std::vector<std::string>::size_type;
	TextQuery(std::ifstream&);
	QueryResult query(const std::string&) const;
private:
	//std::shared_ptr<std::vector<std::string>> file;
	StrBlob file;
	std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;
};


TextQuery::TextQuery(std::ifstream &is)
{
	std::string text;
	while (getline(is, text))
	{
		file.push_back(text);
		int n = file.size() -1;
		std::istringstream line(text);
		std::string word;
		while (line >> word)
		{
			auto &lines = wm[word];
			if (!lines)
				lines.reset(new std::set<TextQuery::line_no>);
			lines->insert(n);
		}
	}
}


class QueryResult
{
friend std::ostream& print(std::ostream&, const QueryResult&);
public:
	QueryResult(std::string s, 
		    std::shared_ptr<std::set<TextQuery::line_no>> p,
		    StrBlob f) :
		    sought(s), lines(p), file(f)  {  }
private:
	std::string sought;
	std::shared_ptr<std::set<TextQuery::line_no>> lines;
	StrBlob file;
};


QueryResult TextQuery::query(const std::string &sought) const
{
	static std::shared_ptr<std::set<TextQuery::line_no>> nodata(new std::set<TextQuery::line_no>);
	auto loc = wm.find(sought);
	if (loc == wm.end())
		return QueryResult(sought, nodata, file);
	else
		return QueryResult(sought, loc->second, file);
}


std::ostream &print(std::ostream &os, const QueryResult &qr)
{
	os << qr.sought << " occurs " << qr.lines->size() << " times." << std::endl;
	for (auto num : *qr.lines)
		os << "\t(line " << num+1 << ") " << ConstStrBlobPtr(qr.file,num).deref() << std::endl;
	return os;
}


void runQueries(std::ifstream &infile)
{
	TextQuery tq(infile);
	while (true)
	{
		std::cout << "enter word to look for, or q to quit: ";
		std::string s;
		if (!(std::cin>>s) || s == "q") break;
		print(std::cout, tq.query(s)) << std::endl;
	}
}


int main(int argv, char** argc)
{
	std::ifstream ifs(argc[1]);
	
	runQueries(ifs);

	return 0;

}











