#include <iostream>
#include <string>
#include <regex>

int main()
{
	std::string pattern("[^c]ei");
	pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*";
	std::regex r(pattern);

	std::smatch results;
	std::string text = "Hello there being not using correct English. How theirfore art thou?";

	for(std::sregex_iterator it(text.begin(), text.end(), r), end; it != end; ++it)
	{
		std::cout << it->str() << std::endl;
	}


	return 0;
}
