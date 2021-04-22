#include <iostream>
#include <list>
#include <string>
#include <algorithm>

using std::list;
using std::string;
using std::count;

int main()
{
	list<string> l{"Hello", "Josh", "how", "are", "you", "today", "Josh"};
	string s_to_count = "Ted";

	std::cout << count(l.begin(), l.end(), s_to_count) << std::endl;	


	return 0;
}
