#include <iostream>
#include <string>
#include <map>
#include <set>
#include <algorithm>

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
		// Change Every Character to Lowercase
		auto it = word.begin();
		while (it != word.end())
		{
			*it = tolower(*it);
			++it;
		}

		// Remove All Punctuation
		it = find_if(word.begin(), word.end(), ispunct);
		while (it != word.end())
		{
			word.erase(it, it+1);
			it = find_if(word.begin(), word.end(), ispunct);
		}

		// Exclude from the set above
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
