#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;

int main()
{
	vector<string> input_words;
	string input_word;
	while(cin >> input_word)
	{
		input_words.push_back(input_word);
	}

	for(auto &w : input_words)
	{
		for(auto &c : w)
		{
			c = std::toupper(c);
		}	
	}

	int i = 0;
	for(auto w: input_words)
	{
		cout << w << " ";
	
		if (i%8 == 7)
			cout << endl;
	
		++i;	
	}

	return 0;
}
