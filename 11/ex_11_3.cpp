#include <iostream>
#include <string>
#include <map>
#include <set>

using std::string;
using std::map;
using std::set;
using std::cin;
using std::cout;
using std::endl;

int main()
{
	map<string, size_t> word_count;
	set<string> exclude = {"The", "But", "And", "Or", "An", "A",
				"the", "but", "and", "or", "an", "a"};

	string word;
	while (cin >> word)
	{
		if (exclude.find(word) == exclude.end())
		{
			++word_count[word];
		}
	}

	for (auto &wc : word_count)
	{
		cout << wc.first << " occurs " << wc.second << " times" << endl;
	}

	return 0;
}
