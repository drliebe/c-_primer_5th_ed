#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iterator>

using std::vector;
using std::string;
using std::ifstream;
using std::ofstream;
using std::istream_iterator;
using std::ostream_iterator;
using std::back_inserter;

int main(int argc, char **argv)
{
	string in_filename(argv[1]);
	string odd_filename(argv[2]);
	string even_filename(argv[3]);

	vector<int> ivec;

	ifstream ifs(in_filename);
	istream_iterator<int> in_it(ifs), in_eof;

	copy(in_it, in_eof, back_inserter(ivec));

	ofstream odd_ofs(odd_filename);
	ofstream even_ofs(even_filename);

	ostream_iterator<int> odd_it(odd_ofs, " ");
	ostream_iterator<int> even_it(even_ofs, "\n");

	for (auto i: ivec)
	{
		if (i%2 == 0)
		{
			*even_it++ = i;
		}
		else
		{
			*odd_it++ = i;
		}
	}
	odd_ofs.close();
	even_ofs.close();

	return 0;
}
