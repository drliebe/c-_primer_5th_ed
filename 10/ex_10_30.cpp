#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using std::vector;
using std::sort;
using std::copy;
using std::back_inserter;
using std::cin;
using std::cout;
using std::istream_iterator;
using std::ostream_iterator;

int main()
{
	vector<int> ivec;

	istream_iterator<int> in_it(cin), in_eof;

	copy(in_it, in_eof, back_inserter(ivec));

	sort(ivec.begin(), ivec.end());

	ostream_iterator<int> out_it(cout, " ");

	copy(ivec.begin(), ivec.end(), out_it);

	cout << std::endl;

	return 0;
}
