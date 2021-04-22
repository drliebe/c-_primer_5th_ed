#include <iostream>
#include <random>


static std::default_random_engine e;
static std::uniform_int_distribution<unsigned> u(0,9);

unsigned int random_josh()
{
	return u(e);
}

unsigned int random_josh(unsigned int desired_seed)
{
	e.seed(desired_seed);
	return random_josh();
}


int main()
{


	std::cout << "Enter seed: " << std::endl;

	int desired_seed;
	std::cin >> desired_seed;

	std::cout << random_josh(desired_seed) << std::endl;
	std::cout << random_josh() << std::endl;
	std::cout << random_josh() << std::endl;
	std::cout << random_josh() << std::endl;
	std::cout << random_josh() << std::endl;
	return 0;
}
