#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>

using std::multimap;
using std::string;
using std::vector;
using std::cout;
using std::endl;
using std::pair;


void print_bibliography(multimap<string, string> &bib)
{
	auto it = bib.begin();
	while (it != bib.end())
	{
		vector<string> books;
		for(auto pos = bib.equal_range(it->first);
			pos.first != pos.second; ++pos.first)
		{
			books.push_back(pos.first->second);
		}
		sort(books.begin(), books.end());
		for( auto b : books)
		{
			cout << "Author: " << it->first << " Book: " << b << endl; 
		}
		it = bib.upper_bound(it->first);
	}

	return;
}



int main()
{
	multimap<string, string> bibliography = {
							{"Tolstoy","Book 3"},
							{"Tolstoy","Book 2"},
							{"Tolstoy","Book 1"},
							{"Twain","Book B"},
							{"Twain","Book A"},
							{"Steele","Book Red"}	};
	print_bibliography(bibliography);

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

	print_bibliography(bibliography);

	return 0;
}
