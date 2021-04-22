#include <iostream>

int main()
{
	int x = 5;
	auto f = [x] (int a) -> int {return a+x;};

	std::cout << f(1) << std::endl;

	return 0;
}
