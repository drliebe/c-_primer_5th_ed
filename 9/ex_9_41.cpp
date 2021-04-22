#include <iostream>
#include <string>
#include <vector>


using std::string;
using std::vector;

int main()
{
	vector<char> vchar{'J', 'o', 's', 'h'};

//	string s(vchar.begin(), vchar.end());
	string s(vchar.begin(), vchar.begin()+4);


	std::cout << s << std::endl;

	return 0;
}
