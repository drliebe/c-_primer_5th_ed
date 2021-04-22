#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::sort;
using std::unique;
using std::stable_sort;
using std::bind;
using namespace std::placeholders;

void elimDups(vector<string> &words)
{
	sort(words.begin(), words.end());
	auto end_unique = unique(words.begin(), words.end());
	words.erase(end_unique, words.end());
	return;
}


bool check_size(const string &s, string::size_type sz)
{
	return s.size() >= sz;
}


void biggies(vector<string> &words, vector<string>::size_type sz)
{
	elimDups(words);

	auto part_it = partition(words.begin(), words.end(), bind(check_size, _1, sz) );

	for_each(words.begin(), part_it, [](const string &s){cout << s << " ";} );
	cout << std::endl;

}

int main()
{
	vector<string>::size_type desired_sz = 4;
	vector<string> text{"the","quick","red","fox","jumps","over","the","slow","red","turtle"};

	biggies(text, desired_sz);

	return 0;
}
