#include <iostream>
#include <string>
#include <regex>

int main()
{
	std::string pattern("[^c]ei");
	pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*";
	std::regex r(pattern);

	std::smatch results;
	std::string query_word;
	std::cout << "Enter word to test: " << std::endl;
	while (std::cin >> query_word)
	{
		if (std::regex_search(query_word, results, r))
			std::cout << "Not Okay: " << results.str() << std::endl;
		else
			std::cout << "Okay" << std::endl;
	}

	return 0;
}
