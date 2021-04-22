#include <iostream>
#include <vector>

struct X
{
	X() {std::cout << "X()" << std::endl;}
	X(const X &cp) {std::cout << "X(const X &cp)" << std::endl;}
	X &operator=(const X &rhs) {std::cout << "operator=(const X &rhs)" << std::endl;}
	~X() {std::cout << "~X()" << std::endl;}
};


int main()
{
/*	X a;
	X b(a);
	X c;
	c = a;
*/
/*
	X *pa = new X();
	X b(*pa);
	X *pc = new X();
	*pc = *pa;
	delete pa;
	delete pc;
*/
/*	std::vector<X> vx;
	X a;
	vx.push_back(a);
*/
	std::vector<X> vx;
	X *pa = new X();
	vx.push_back(*pa);
	delete pa;

	return 0;
}
