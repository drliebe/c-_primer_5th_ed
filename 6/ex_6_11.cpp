#include <iostream>

void reset(int &i)
{
	i = 0;
	return;
}

int main()
{
	int a = 54;
	reset(a);
	std::cout << "a = " << a << std::endl;

	return 0;

}
