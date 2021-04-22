#include <iostream>

int main()
{
	int array[10] = {};

	for(std::size_t i=0; i<10; ++i)
	{
		array[i] = i;
	}

	for(std::size_t j=0; j<10; ++j)
	{
		std::cout << array[j] << std::endl;
	}

	return 0;
}
