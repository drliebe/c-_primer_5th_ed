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
using namespace std::placeholders;

void elimDups(vector<string> &words)
{
	sort(words.begin(), words.end());
	auto end_unique = unique(words.begin(), words.end());
	words.erase(end_unique, words.end());
	return;
}


bool larger_than(const string &a, vector<string>::size_type larger_than_sz)
{
	return a.size() >= larger_than_sz;
}

void biggies(vector<string> &words, vector<string>::size_type sz)
{
	elimDups(words);
	stable_sort(words.begin(), words.end(), 
		[] (const string &a, const string &b)
			{return a.size() < b.size();});

	auto wc = find_if(words.begin(), words.end(), 
		[sz] (const string &a)
			{return a.size() >= sz;});

	auto count = count_if(words.begin(), words.end(), bind(larger_than, _1, sz) );

	cout << count << " words of length " << sz << " or longer" << std::endl;

	for_each(wc, words.end(), 
		[] (const string &s) {cout << s << " ";} );
	cout << endl;
}

int main()
{
	vector<string>::size_type desired_sz = 4;
	vector<string> text{"the","quick","red","fox","jumps","over","the","slow","red","turtle"};

	biggies(text, desired_sz);

	return 0;
}
