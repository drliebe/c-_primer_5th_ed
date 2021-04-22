#include <iostream>
#include <string>

int main()
{
	std::string last_word = "";
	std::string input_word = "";

	while(std::cin >> input_word)
	{
		if ((input_word == last_word) && (std::isupper(input_word[0])))
		{
			std::cout << last_word << " occured twice." << std::endl;
			break;
		}
		else 
		{
			last_word = input_word;
		}
	}
	if (!std::cin)
	{
		std::cout << "No capitalized word was repeated. " << std::endl;
	}

	return 0;
}
