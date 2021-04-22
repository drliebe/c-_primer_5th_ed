#include <iostream>
#include <map>
#include <string>

using std::multimap;
using std::string;
using std::cout;
using std::endl;

int main()
{
	multimap<string, string> bibliography = {
							{"Tolstoy","Book 1"},
							{"Tolstoy","Book 2"},
							{"Tolstoy","Book 3"},
							{"Twain","Book A"},
							{"Twain","Book B"},
							{"Steele","Book Red"}	};

	for(auto entry : bibliography)
	{
		cout << entry.first << " wrote " << entry.second << endl;
	}

	string author_to_erase = "Steele";
	string book_to_erase = "Book Red";
	auto it = bibliography.find(author_to_erase);
	auto count = bibliography.count(author_to_erase);

	if (it != bibliography.end())
	{
		for(int j = 0; j<count; ++j)
		{
			if (it->second == book_to_erase)
				it = bibliography.erase(it);

			++it;
		}
	}


	for(auto entry : bibliography)
	{
		cout << entry.first << " wrote " << entry.second << endl;
	}

	return 0;
}
