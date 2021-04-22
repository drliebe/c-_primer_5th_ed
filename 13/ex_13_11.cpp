#include <iostream>
#include <string>

class HasPtr
{
public:
	HasPtr(const std::string &s = std::string()): 
		ps(new std::string(s)), i(0) { }
	HasPtr(const HasPtr &c);
	HasPtr &operator=(const HasPtr &rhs);
	~HasPtr() { }
private:
	std::string *ps;
	int i;
};

HasPtr::HasPtr(const HasPtr &c) : ps(new std::string(*c.ps)), i(c.i) 
{
	
}

HasPtr & HasPtr::operator=(const HasPtr &rhs)
{
	ps = new std::string(*rhs.ps);
	i = rhs.i;
	return *this;
}


int main()
{
	HasPtr p1;
	HasPtr p2 = p1;
	HasPtr p3;
	p3 = p2;

	return 0;
}
