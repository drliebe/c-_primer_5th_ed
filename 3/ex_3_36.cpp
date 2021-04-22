#include <iostream>
#include <vector>

using std::vector;

int main()
{
	int array1[5] = {1,2,3,4,5};
	int array2[5] = {1,2,3,4,6};

	bool equal = true;

	for(int i=0; i<5; ++i)
	{
		if((array1[i]) != (array2[i]))
			equal = false;
	}

	std::cout << "Equal? " << equal << std::endl;


	vector<int> vec1 = {1,2,3,4,5};
	vector<int> vec2 = {1,2,3,4,6};
	std::cout << "Equal? " << (vec1 == vec2) << std::endl;

	return 0;
}
