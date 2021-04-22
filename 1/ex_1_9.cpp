#include <iostream>

int main () 
{

	int sum=0, val=50;

	while (val<=100)
	{
		sum += val;
		++val;
	}

	std::cout << "Sum from 50 to 100 inclusive is: " << sum << std::endl;
	
	return 0;
}
