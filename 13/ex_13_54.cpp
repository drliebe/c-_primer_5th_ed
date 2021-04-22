#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class HasPtr
{
public:
	HasPtr(const std::string &s = std::string()): 
		ps(new std::string(s)), i(0) { }
	HasPtr(const HasPtr &c);
	HasPtr(HasPtr &&c);
	HasPtr &operator=(HasPtr rhs);
	HasPtr &operator=(HasPtr &&rhs);
	bool operator<(const HasPtr &rhs);
	~HasPtr() { delete ps; }
	friend void swap(HasPtr &left, HasPtr &right);
	std::string string() { return *ps; }
private:
	std::string *ps;
	int i;
};

HasPtr::HasPtr(const HasPtr &c) : ps(new std::string(*c.ps)), i(c.i) 
{
	
}

HasPtr::HasPtr(HasPtr &&c) : ps(c.ps), i(c.i)
{
	c.ps = nullptr;
}

HasPtr & HasPtr::operator=(HasPtr rhs)
{
	swap(*this, rhs);
	return *this;
}

HasPtr &HasPtr::operator=(HasPtr &&rhs)
{
	if (this != &rhs)
	{
		delete ps;
		ps = rhs.ps;
		i = rhs.i;
		rhs.ps = nullptr;		
	}
	return *this;

}


bool HasPtr::operator<(const HasPtr &rhs)
{
	return (*ps < *rhs.ps);
}

inline void swap(HasPtr &l, HasPtr &r)
{
	using std::swap;
	swap(l.ps, r.ps);
	swap(l.i, r.i);
	std::cout << "swap(HasPtr &l, HasPtr &r)" << std::endl;
}


int main()
{
	HasPtr a("a");
	HasPtr b("b");
	swap(a,b);

	std::vector<HasPtr> vec = {HasPtr("D"), HasPtr("B"), HasPtr("C"), HasPtr("A") };
	std::cout << vec.size() << std::endl;
	for(auto p : vec)
	{
		std::cout << p.string() << std::endl;
	}


	std::sort(vec.begin(), vec.end());		


	std::cout << vec.size() << std::endl;
	for(auto p : vec)
	{
		std::cout << p.string() << std::endl;
	}
	return 0;
}
