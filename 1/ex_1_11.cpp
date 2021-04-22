#include <iostream>
#include <cmath>

int main ()
{
	int val1 = 0, val2 = 0;
	std::cout << "Enter two numbers" << std::endl;
	std::cin >> val1 >> val2;
	int min = std::min(val1, val2);
	int max = std::max(val1, val2);
	int value = min;
	while (value <= max)
	{
		std::cout << value << std::endl;
		++value;
	}

	return 0;
}
