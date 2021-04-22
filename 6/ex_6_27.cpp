#include <iostream>
#include <initializer_list>

int sum(std::initializer_list<int> values)
{
	int sum = 0;
	
	for(auto &i: values)
	{
		sum += i;
	}
	return sum;
}

int main()
{
	int value = 0;
	value = sum({1,2,3,4,5});
	std::cout << value << std::endl;

	return 0;
}
