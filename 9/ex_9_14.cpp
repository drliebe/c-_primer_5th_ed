#include <iostream>
#include <list>
#include <vector>
#include <string>

using std::list;
using std::vector;
using std::string;

int main()
{
	list<char *> cstrs{"One", "Two", "Three", "Four"};
	vector<string> str{"Initial", "Strings"};

	str.assign(cstrs.begin(), cstrs.end());

	for(auto s : str)
	{
		std::cout << s << " " << std::endl;
	}

	return 0;
}
