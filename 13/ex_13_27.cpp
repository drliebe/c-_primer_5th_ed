#include <iostream>
#include <string>

class HasPtr
{
public:
	HasPtr(const std::string &s = std::string()): 
		ps(new std::string(s)), i(0), use(new std::size_t(1)) { }
	HasPtr(const HasPtr &c);
	HasPtr &operator=(const HasPtr &rhs);
	~HasPtr();
private:
	std::string *ps;
	int i;
	std::size_t *use;
};

HasPtr::HasPtr(const HasPtr &c) : ps(c.ps), i(c.i), use(c.use) 
{
	++*use;
}

HasPtr & HasPtr::operator=(const HasPtr &rhs)
{
	++*rhs.use;
	if (--*use == 0)
		delete ps;

	ps = rhs.ps;
	use = rhs.use;

	return *this;
}

HasPtr::~HasPtr()
{
	if (--*use == 0)
	{
		delete ps;
		delete use;
	}
}


int main()
{
	HasPtr p1;
	HasPtr p2 = p1;
	HasPtr p3;
	p3 = p2;

	return 0;
}
