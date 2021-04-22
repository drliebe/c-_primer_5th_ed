#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using std::string;
using std::vector;
using std::sort;
using std::unique;

void elimDups(vector<string> &words)
{
	for(auto s: words)
	{
		std::cout << s << " ";
	}
	std::cout << std::endl << " " << std::endl;

	sort(words.begin(), words.end());

	for(auto s: words)
	{
		std::cout << s << " ";
	}
	std::cout << std::endl << " " << std::endl;

	auto end_unique = unique(words.begin(), words.end());

	for(auto s: words)
	{
		std::cout << s << " ";
	}
	std::cout << std::endl << " " << std::endl;

	words.erase(end_unique, words.end());

	for(auto s: words)
	{
		std::cout << s << " ";
	}
	std::cout << std::endl << " " << std::endl;

	return;
}

int main()
{
	vector<string> text{"the","quick","red","fox","jumps","over","the","slow","red","turtle"};

	elimDups(text);

	return 0;
}
