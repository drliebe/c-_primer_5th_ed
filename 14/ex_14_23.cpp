#include <iostream>
#include <string>
#include <fstream>
#include <memory>
#include <vector>
#include <map>
#include <set>
#include <sstream>
#include <utility>
#include <initializer_list>
#include <algorithm>
#include <iterator>

class StrVec
{
public:
	StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) { }
	StrVec(std::initializer_list<std::string> il);
	StrVec(const StrVec &cp);
	StrVec(StrVec &&cp) noexcept;
	StrVec &operator=(const StrVec &rhs);
	StrVec &operator=(StrVec &&rhs) noexcept;
	StrVec &operator=(std::initializer_list<std::string> &rhs);
	~StrVec();
	void push_back(const std::string &s);
	size_t size() const { return first_free - elements; }
	size_t capacity() const { return cap - elements; }
	void reserve(size_t n);
	void resize(size_t n);
	std::string *begin() const { return elements; }
	std::string *end() const { return first_free; }
	friend bool operator==(const StrVec &lhs, const StrVec &rhs);
	friend bool operator!=(const StrVec &lhs, const StrVec &rhs);
	friend bool operator<(const StrVec &lhs, const StrVec &rhs);
	friend bool operator>(const StrVec &lhs, const StrVec &rhs);

private:
	static std::allocator<std::string> alloc;
	void chk_n_alloc() { if (size() == capacity()) reallocate(); }
	std::pair<std::string*, std::string*> alloc_n_copy(const std::string*, const std::string*);
	void free();
	void reallocate();
	std::string *elements;
	std::string *first_free;
	std::string *cap;
};

std::allocator<std::string> StrVec::alloc;

void StrVec::push_back(const std::string& s)
{
	chk_n_alloc();
	alloc.construct(first_free++, s);
}

void StrVec::reserve(size_t n)
{
	if (n > capacity())
	{
		auto newcapacity = n;
		auto newdata = alloc.allocate(newcapacity);
		auto dest = newdata;
		auto elem = elements;
		for (size_t i=0; i !=size(); ++i)
			alloc.construct(dest++, std::move(*elem++));
		free();
		elements = newdata;
		first_free = dest;
		cap = elements + newcapacity;
	}
}

void StrVec::resize(size_t n)
{
	if (n < size())
	{
		auto newcapacity = n;
		auto newdata = alloc.allocate(newcapacity);
		auto dest = newdata;
		auto elem = elements;
		for (size_t i=0; i !=n; ++i)
			alloc.construct(dest++, std::move(*elem++));
		free();
		elements = newdata;
		first_free = dest;
		cap = elements + newcapacity;

	} else if (n > size())
	{
		auto newcapacity = n;
		auto newdata = alloc.allocate(newcapacity);
		auto dest = newdata;
		auto elem = elements;
		for (size_t i=0; i !=size(); ++i)
			alloc.construct(dest++, std::move(*elem++));
		for (size_t j=size(); j != newcapacity; ++j)
			alloc.construct(dest++, std::string());
		free();
		elements = newdata;
		first_free = dest;
		cap = elements + newcapacity;
	} else 
	{
	// Already equal in size to n, do nothing.
	}	
}


std::pair<std::string*, std::string*> StrVec::alloc_n_copy(const std::string *b, const std::string *e)
{
	auto data = alloc.allocate(e-b);
	return {data, uninitialized_copy(b,e,data)};
}

void StrVec::free()
{
	if (elements)
	{
		//for (auto p= first_free; p != elements; )
		//	alloc.destroy(--p);
		for_each(elements, first_free, 
			[] (std::string &s) { alloc.destroy(&s); });
		alloc.deallocate(elements, cap - elements);	
	}
}

StrVec::StrVec(std::initializer_list<std::string> il) : elements(nullptr), first_free(nullptr), cap(nullptr)
{
	for (auto s : il)
		push_back(s);
	
}

StrVec::StrVec(const StrVec &s)
{
	auto newdata = alloc_n_copy(s.begin(), s.end());
	elements = newdata.first;
	first_free = newdata.second;
	cap = newdata.second;
}

StrVec::StrVec(StrVec &&s) noexcept : elements(s.elements), first_free(s.first_free), cap(s.cap)
{
	s.elements = s.first_free = s.cap = nullptr;
}

StrVec::~StrVec()
{
	free();
}

StrVec &StrVec::operator=(const StrVec &rhs)
{
	auto data = alloc_n_copy(rhs.begin(), rhs.end());
	free();
	elements = data.first;
	first_free = data.second;
	cap = data.second;
	return *this;
}

StrVec &StrVec::operator=(StrVec &&rhs) noexcept
{
	if (this != &rhs)
	{
		free();
		elements = rhs.elements;
		first_free = rhs.first_free;
		cap = rhs.cap;
		rhs.elements = rhs.first_free = rhs.cap = nullptr;
	}
	return *this;
}

StrVec &StrVec::operator=(std::initializer_list<std::string> &rhs)
{
	auto data = alloc_n_copy(rhs.begin(), rhs.end());
	free();
	elements = data.first;
	first_free = data.second;
	cap = data.second;
	return *this;
}

void StrVec::reallocate()
{
	auto newcapacity = size() ? 2*size() : 1;
	auto newdata = alloc.allocate(newcapacity);
	auto dest = newdata;
	auto elem = elements;
	for (size_t i=0; i !=size(); ++i)
		alloc.construct(dest++, std::move(*elem++));
	free();
	elements = newdata;
	first_free = dest;
	cap = elements + newcapacity;
}

bool operator==(const StrVec &lhs, const StrVec &rhs)
{
	return (lhs.elements == rhs.elements) && (lhs.first_free == rhs.first_free) && (lhs.cap == rhs.cap);
}

bool operator!=(const StrVec &lhs, const StrVec &rhs)
{
	return !(lhs == rhs);
}

bool operator<(const StrVec &lhs, const StrVec &rhs)
{
	std::vector<std::string> l(lhs.elements, lhs.first_free);
	std::vector<std::string> r(rhs.elements, rhs.first_free);
	return l < r;
}

bool operator>(const StrVec &lhs, const StrVec &rhs)
{
	return (rhs < lhs);
}


class QueryResult;
class TextQuery
{
public:
	using line_no = size_t;
	TextQuery(std::ifstream&);
	QueryResult query(const std::string&) const;
private:
	std::shared_ptr<StrVec> file;
	std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;
};

TextQuery::TextQuery(std::ifstream &is) : file(new StrVec)
{
	std::string text;
	while (getline(is, text))
	{
		file->push_back(text);
		int n = file->size() -1;
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
		    std::shared_ptr<StrVec> f) :
		    sought(s), lines(p), file(f)  {  }
	std::set<TextQuery::line_no>::iterator begin() {return lines->begin();}
	std::set<TextQuery::line_no>::iterator end()   {return lines->end();}
	std::shared_ptr<StrVec> get_file() {return file;}
private:
	std::string sought;
	std::shared_ptr<std::set<TextQuery::line_no>> lines;
	std::shared_ptr<StrVec> file;
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
		os << "\t(line " << num+1 << ") " << *(qr.file->begin() + num) << std::endl;
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











