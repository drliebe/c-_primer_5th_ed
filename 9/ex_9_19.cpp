#include <iostream>
#include <list>
#include <string>

using std::list;
using std::string;

int main()
{
	string input_word;
	list<string> l1;

	while(std::cin >> input_word)
	{
		l1.push_back(input_word);
	}

	std::cout << "Echoing input. " << std::endl;

	for(auto s : l1)
	{
		std::cout << (s) << std::endl;
	}

	std::cout << "Second Echo. " << std::endl;

	for(list<string>::iterator it=l1.begin(); it != l1.end(); ++it)
	{
		std::cout << (*it) << std::endl;
	}

	return 0;
}
