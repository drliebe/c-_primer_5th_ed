#include <iostream>
#include <random>



unsigned int random_josh(unsigned int min = 0, unsigned int max = 1)
{
	static std::default_random_engine e;
	static std::uniform_int_distribution<unsigned> u(min,max);
	
	return u(e);
}




int main()
{
	std::cout << "Enter min: " << std::endl;
	int desired_min;
	std::cin >> desired_min;

	std::cout << "Enter max: " << std::endl;
	int desired_max;
	std::cin >> desired_max;

	std::cout << random_josh(desired_min, desired_max) << std::endl;
	std::cout << random_josh(desired_min, desired_max) << std::endl;
	std::cout << random_josh(desired_min, desired_max) << std::endl;
	std::cout << random_josh(desired_min, desired_max) << std::endl;
	std::cout << random_josh(desired_min, desired_max) << std::endl;
	return 0;
}
