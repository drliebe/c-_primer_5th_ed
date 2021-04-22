#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::sort;
using std::unique;
using std::stable_sort;

void elimDups(vector<string> &words)
{
	sort(words.begin(), words.end());
	auto end_unique = unique(words.begin(), words.end());
	words.erase(end_unique, words.end());
	return;
}

class ShorterString
{
public:
	ShorterString() = default;
	bool operator()(const string &a, const string &b) { return a.size() < b.size(); }
};

class LongerThan
{
public:
	LongerThan(size_t n) : sz(n) { }
	bool operator()(const string &a) { return a.size() >= sz; }
private:
	size_t sz;
};

class PrintString
{
public:
	PrintString(std::ostream &o = std::cout, char c = ' ') : os(o), sep(c) { }
	void operator()(const string &s) { os << s << sep; }
private:
	std::ostream &os;
	char sep;
};

void biggies(vector<string> &words, vector<string>::size_type sz)
{
	elimDups(words);
	stable_sort(words.begin(), words.end(), ShorterString());

	auto wc = find_if(words.begin(), words.end(), LongerThan(sz));

	auto count = words.end() - wc;
	cout << count << " words of length " << sz << " or longer" << std::endl;

	for_each(wc, words.end(), PrintString());
	cout << endl;
}

int main()
{
	vector<string>::size_type desired_sz = 4;
	vector<string> text{"the","quick","red","fox","jumps","over","the","slow","red","turtle"};

	biggies(text, desired_sz);

	return 0;
}
