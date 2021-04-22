#include <iostream>

int larger_number(const int &a, const int *b)
{
	return (a > (*b)) ? a : (*b);

}

int main()
{
	int x = 53;
	int *y;
	*y = 10;
	std::cout << larger_number(x, y) << std::endl;

	return 0;
}
