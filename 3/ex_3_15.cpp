#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
	vector<string> string_list;
	string input_string;
	
	while(cin >> input_string)
	{
		string_list.push_back(input_string);
	}

	cout << "Vector Size " << string_list.size() << endl;

	return 0;
}
