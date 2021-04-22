#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

using std::string;
using std::vector;
using std::find_if;
using std::bind;
using namespace std::placeholders;

bool check_size(const string &s, string::size_type sz)
{
	return s.size() >= sz;
}


int main()
{
	vector<int> ivec{1,2,1,0,5,7,12,9,10};
	string s = "Hello";

	auto it = partition(ivec.begin(), ivec.end(), bind(check_size, s, _1) );

	std::cout << *it << std::endl;

	return 0;
}
