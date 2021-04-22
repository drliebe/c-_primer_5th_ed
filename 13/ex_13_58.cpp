#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

class Foo
{
public:
	Foo() = default;
	Foo(const Foo &orig);
	Foo(Foo &&orig);
	Foo &operator=(const Foo &rhs);
	Foo &operator=(Foo &&rhs);
	~Foo() = default;
	Foo sorted() &&;
	Foo sorted() const &;
private:
	std::vector<int> data;
};


Foo::Foo(const Foo &orig) : data(orig.data)
{
	std::cout << "Foo::Foo(const Foo &orig)" << std::endl;
}

Foo::Foo(Foo &&orig) : data(std::move(orig.data))
{
	orig.data.clear();
	std::cout << "Foo::Foo(Foo &&orig)" << std::endl; 
}

Foo &Foo::operator=(const Foo &rhs)
{
	data = rhs.data;
	std::cout << "Foo &Foo::operator=(const Foo &rhs)" << std::endl;
	return *this;
}

Foo &Foo::operator=(Foo &&rhs)
{
	data = std::move(rhs.data);
	rhs.data.clear();
	std::cout << "Foo &Foo::operator=(Foo &&rhs)" << std::endl;
	return *this;
}

Foo Foo::sorted() &&
{
	std::cout << "Foo Foo::sorted() &&" << std::endl;
	std::sort(data.begin(), data.end());
	return *this;
}
/*
Foo Foo::sorted() const &
{
	Foo ret(*this);
	std::sort(ret.data.begin(), ret.data.end());
	return ret;
}
*/
/*
Foo Foo::sorted() const &
{
	// This should have an infinite recursion of definitions.
	Foo ret(*this);
	return ret.sorted();
}
*/
Foo Foo::sorted() const &
{
	// This should call the rvalue reference version of sorted.
	return Foo(*this).sorted();
}


int main()
{
	Foo f1;
	f1.sorted();
	return 0;
}


