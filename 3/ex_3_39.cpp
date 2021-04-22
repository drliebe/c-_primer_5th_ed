#include <iostream>
#include <string>
#include <cstring>

int main()
{
	std::string s1 = "String 1 sucks";
	std::string s2 = "String 1 sucks";
	std::cout << "Equal? " << (s1 == s2) << std::endl;

	char cs1[] = "C String 1 sucks";
	char cs2[] = "C String 1 sucks";
	std::cout << "Equal? " << strcmp(cs1, cs2) << std::endl;


	return 0;
}
