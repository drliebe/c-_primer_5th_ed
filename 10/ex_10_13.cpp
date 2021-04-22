#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using std::string;
using std::vector;
using std::partition;

bool five_or_more(string &s)
{
	return s.size() >= 5;
}


int main()
{
	vector<string> words{"the","quick","red","fox","jumps","over","the","slow","red","turtle"};

	auto part_it = partition(words.begin(), words.end(), five_or_more);

	auto beg_it = words.begin();

	while (beg_it != part_it)
	{
		std::cout << *beg_it << " ";
		++beg_it;
	}
	std::cout << std::endl;

	return 0;
}
