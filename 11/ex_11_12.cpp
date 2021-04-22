#include <string>
#include <iostream>
#include <utility>
#include <vector>

using std::string;
using std::vector;
using std::pair;
using std::cin;
using std::cout;
using std::endl;

int main()
{
	string text;
	int number;
	vector<pair<string,int>> pair_vec;

	while (cin >> text >> number)
	{
		pair_vec.push_back(make_pair(text,number));		
	}

	for(auto p : pair_vec)
	{
		cout << p.first << " " << p.second << endl;
	}

	return 0;
}
