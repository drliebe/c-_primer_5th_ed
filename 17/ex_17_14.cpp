#include <iostream>
#include <regex>
#include <string>

int main()
{
	std::string pattern = "[H]*";
	std::regex r(pattern);

	std::string test_string = "Hello there";

	std::smatch m;
	bool success;

	success = std::regex_search(test_string, m, r);

	std::cout << m.str() << std::endl;

	return 0;
}
