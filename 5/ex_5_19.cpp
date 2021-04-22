#include <iostream>
#include <string>

int main()
{
	do
	{
		std::cout << "Enter two strings." << std::endl;
		std::string s1, s2;
		std::cin >> s1 >> s2;
		if (s1 < s2)
			std::cout << s1 << " < " << s2 << std::endl;
		if (s2 < s1) 
			std::cout << s2 << " < " << s1 << std::endl;
		if (s1 == s2)
			std::cout << s1 << " == " << s2 << std::endl;
	}
	while (std::cin);

	return 0;
}
