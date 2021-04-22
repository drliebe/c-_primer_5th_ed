#include <iostream>
#include <deque>
#include <string>

using std::deque;
using std::string;

int main()
{
	string input_word;
	deque<string> d1;

	while(std::cin >> input_word)
	{
		d1.push_back(input_word);
	}

	std::cout << "Echoing input. " << std::endl;

	for(auto s : d1)
	{
		std::cout << (s) << std::endl;
	}

	std::cout << "Second Echo. " << std::endl;

	for(deque<string>::iterator it=d1.begin(); it != d1.end(); ++it)
	{
		std::cout << (*it) << std::endl;
	}

	return 0;
}
