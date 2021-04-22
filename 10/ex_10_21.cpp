#include <iostream>


int main()
{
	int i=10;
	auto f = [&i] () -> bool {if (i>0){--i;} return i==0;};

	while (!f())
	{
		std::cout << "Not yet..." << std::endl;
	}
	std::cout << "Now it is zero." << std::endl;

	return 0;
}
