#include <iostream>

int main () 
{
	std::cout << "Enter two numbers: " << std::endl;
	int v1 = 0, v2 = 0;
	std::cin >> v1 >> v2;
	std::cout << "The sum of " << v1;
	          << " and " << v2;
	          << " is " << v1+v2 << std::endl;
	/*
	The above fails because there is no ostream object to the left of <<
	on lines 9 and 10.
 
	This can be fixed by deleting the ; on lines 8 and 9 to make this one
	long statement.

	This can also be fixed by add ing std::cout to lines 9 and 10 before 
	the first <<.
	*/

	return 0;
}
