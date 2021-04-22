#include <iostream>

void swap(int *(&x), int *(&y))
{
	int *temp;
	temp = x;
	x = y;
	y = temp;
	return;

}

int main()
{
	int i = 5;
	int j = 10;	
	
	int *x = &i;
	int *y = &j;

	swap(x, y);
	std::cout << (*x) << std::endl;
	std::cout << (*y) << std::endl;


	return 0;
}
