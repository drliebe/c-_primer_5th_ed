#include <iostream>
#include <string>
#include <cstring>

int main()
{
	char cs1[] = "The use of C Strings";
	char cs2[] = " really does suck.";
	char cs3[64];

	strcpy(cs3, cs1);
	strcat(cs3, cs2);

	std::cout << cs3 << std::endl;

	return 0;
}
