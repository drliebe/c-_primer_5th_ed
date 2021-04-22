#include <iostream>
#include <string>
#include <regex>
#include <set>
int main()
{
	std::set<std::string> correct_words = {"albiet", "neighbor"};
	std::string pattern("[^c]ei");
	pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*";
	std::regex r(pattern);

	std::smatch results;
	std::string text = "Hello there being not using correct English. How theirfore art thou? My neighbor is good, albiet I am better.";

	for(std::sregex_iterator it(text.begin(), text.end(), r), end; it != end; ++it)
	{
		if (correct_words.find(it->str()) == correct_words.end())
			std::cout << it->str() << std::endl;
	}


	return 0;
}
