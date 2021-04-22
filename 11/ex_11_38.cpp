#include <iostream>
#include <string>
#include <unordered_map>
#include <set>

using std::string;
using std::unordered_map;
using std::set;
using std::cin;
using std::cout;
using std::endl;

int main()
{
	unordered_map<string, size_t> word_count;
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
