#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iterator>

using std::vector;
using std::string;
using std::ifstream;
using std::cin;
using std::back_inserter;
using std::istream_iterator;

int main()
{
	string filename = "test.txt";
	ifstream ifs(filename);
	istream_iterator<string> ifs_it(ifs), ifs_eof;

	vector<string> text;
	
	copy(ifs_it, ifs_eof, back_inserter(text));

	ifs.close();

	for(auto s: text)
	{
		std::cout << s << " ";
	}
	std::cout << std::endl;

	return 0;
}
