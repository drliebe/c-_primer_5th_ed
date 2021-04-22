#include <iostream>

int main ()
{
	int i = 0, &r = i;
	auto a = r;
	const int ci = i, &cr = ci;
	auto b = ci;
	auto c = cr;
	auto d = &i;
	auto e = &ci;
	const auto f = ci;
	auto &g = ci;

	std::cout << "a before " << a << std::endl;
	a = 42;
	std::cout << "a after " << a << std::endl;
	std::cout << "b before " << b << std::endl;
	b = 42;
	std::cout << "b after " << b << std::endl;
	std::cout << "c before " << c << std::endl;
	c = 42;
	std::cout << "c after " << c << std::endl;
	std::cout << "d before " << d << std::endl;
	*d = 42;
	std::cout << "d after " << d << std::endl;
	std::cout << "e before " << e << std::endl;
	//e = 42;
	std::cout << "e after " << e << std::endl;
	std::cout << "g before " << g << std::endl;
	//g = 42;
	std::cout << "g after " << g << std::endl;


	return 0;
}
