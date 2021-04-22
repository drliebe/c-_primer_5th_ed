#include <iostream>

int main()
{
	int array[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	for(int i=0; i<10; ++i)
	{
		std::cout << array[i] << std::endl;
	}	

	int *p = array;
	for(int j=0; j<10; ++j)
	{
		*(p+j) = 0;
	}

	for(int i=0; i<10; ++i)
	{
		std::cout << array[i] << std::endl;
	}

	return 0;
}
