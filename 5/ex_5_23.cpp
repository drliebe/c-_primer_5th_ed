#include <iostream>
#include <string>

int main()
{
	int i1 = 0, i2 = 0;	

	std::cout << "Enter two integers: " << std::endl;
	std::cin >> i1 >> i2;

	std::cout << i1 << "/" << i2 << " = " << i1/i2 << std::endl;
	
	return 0;
}
