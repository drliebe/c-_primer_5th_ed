#include <iostream>
#include <string>

class HasPtr
{
public:
	HasPtr(const std::string &s = std::string()): 
		ps(new std::string(s)), i(0) { }
	HasPtr(const HasPtr &c);
	HasPtr &operator=(const HasPtr &rhs);
	~HasPtr() { delete ps; }
	friend void swap(HasPtr &left, HasPtr &right);
private:
	std::string *ps;
	int i;
};

HasPtr::HasPtr(const HasPtr &c) : ps(new std::string(*c.ps)), i(c.i) 
{
	
}

HasPtr & HasPtr::operator=(const HasPtr &rhs)
{
	if (this != &rhs)
	{
		std::string *ptemp = new std::string(*rhs.ps);
		delete ps;
		ps = ptemp;
		i = rhs.i;
	}
	return *this;
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
	HasPtr p1;
	HasPtr p2 = p1;
	HasPtr p3;
	p3 = p2;
	swap(p1, p2);
	swap(p2, p3);

	return 0;
}
