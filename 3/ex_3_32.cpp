#include <iostream>
#include <vector>

using std::vector;

int main()
{
	int array[10] = {};

	for(std::size_t i=0; i<10; ++i)
	{
		array[i] = i;
	}

	int array2[10] = {};

	for(std::size_t j=0; j<10; ++j)
	{
		array2[j] = array[j];
	}


	for(std::size_t k=0; k<10; ++k)
	{
		std::cout << "Array 1: " << array[k] << " Array 2: " << array2[k] << std::endl;
	}


	vector<int> vec1;
	for(int i=0; i<10; ++i)
	{
		vec1.push_back(i);
	}

	vector<int> vec2(vec1);

	for(int j=0; j<10; ++j)
	{
		std::cout << "Vector 1: " << vec1[j] << " Vector 2: " << vec2[j] << std::endl;
	}


	return 0;
}
