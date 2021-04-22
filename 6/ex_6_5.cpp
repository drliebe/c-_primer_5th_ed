#include <iostream>


double abs_value(double x)
{
	return (x >= 0.0) ? 1.0*x : -1.0*x;
}


int main()
{
	std::cout << "Abs of -3.14 = " << abs_value(-3.14) << std::endl;
	std::cout << "Abs of 2.718 = " << abs_value(2.718) << std::endl;
	return 0;
}
