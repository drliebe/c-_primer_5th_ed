#include <iostream>
#include <string>
#include <stdexcept>

int main()
{
	int i1 = 0, i2 = 0;	

	std::cout << "Enter two integers: " << std::endl;
	std::cin >> i1 >> i2;

		if (i2 == 0)
			throw std::runtime_error("Division by Zero.");
		
		std::cout << i1 << "/" << i2 << " = " << i1/i2 << std::endl;

	return 0;
}
