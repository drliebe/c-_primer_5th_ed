#include <iostream>
#include <string>

int main()
{
	std::string input_line;
	std::string input_word;
/*	while ( std::getline(std::cin,input_line) )
	{
		std::cout << "I heard:" << input_line << std::endl;
	}
*/

	while (std::cin >> input_word)
	{
		std::cout << "I heard:" << input_word << std::endl;
	}

	return 0;
}
