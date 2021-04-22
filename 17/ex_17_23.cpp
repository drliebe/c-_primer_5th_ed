#include <iostream>
#include <string>
#include <regex>


int main()
{
	std::string zipcode_pattern = 
		"(\\d{5})(-\\d{4}| |\n)";
	std::regex r(zipcode_pattern);
	std::smatch m;
	std::string s;
	while (getline(std::cin, s))
	{
		for (std::sregex_iterator it(s.begin(), s.end(), r), end; it!=end; ++it)
		{
			std::cout << it->str() << std::endl;
		}
	}

	return 0;
}
