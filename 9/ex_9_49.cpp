#include <iostream>
#include <string>
#include <fstream>

using std::string;
using std::ifstream;

int main(int argv, char** argc)
{
	string ascenders{"bdfhijkltABCDEFGHIJKLMNOPQRSTUVWXYZ"};
	string descenders{"gjpqy"};
	

	string filename(argc[1]);
	ifstream ifs;
	ifs.open(filename);

	string word;
	string longest_word;
	while(ifs >> word)
	{
		if ((word.find_first_of(ascenders) == string::npos) && 
			(word.find_first_of(descenders) == string::npos))
		{
			if (word.size() > longest_word.size())
			{
				longest_word = word;
			}
		}
	}
	ifs.close();

	std::cout << "Longest word: " << longest_word << " has " << longest_word.size() << 
		" characters without an ascender or descender." << std::endl;

	return 0;
}
