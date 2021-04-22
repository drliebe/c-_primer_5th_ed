#include <iostream>
#include <string>
#include <stdexcept>

int main()
{
	int i1 = 0, i2 = 0;	

	std::cout << "Enter two integers: " << std::endl;

	while(std::cin >> i1 >> i2)
	{
		try
		{
			if (i2 == 0)
				throw std::runtime_error("Division by Zero.");
			
			std::cout << i1 << "/" << i2 << " = " << i1/i2 << std::endl;
		}
		catch (std::runtime_error err)
		{
			std::cout << "Exception: " << err.what() << std::endl;
			std::cout << "Enter two integers (non-zero): " << std::endl;
		}	
	}
	return 0;
}
