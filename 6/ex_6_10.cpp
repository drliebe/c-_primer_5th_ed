#include <iostream>

void swap(int *a, int *b)
{
	int temp = 0;
	temp = *a;
	*a = *b;
	*b = temp;

	return;
}

int main()
{
	int x = 5;
	int y = 21;
	swap(&x, &y);
	std::cout << "x: " << x << std::endl;
	std::cout << "y: " << y << std::endl;
	
	return 0;
}
