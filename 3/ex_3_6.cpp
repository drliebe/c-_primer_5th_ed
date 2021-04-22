#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

int main()
{
	string input_string;
	cin >> input_string;

	for(auto &c : input_string)
	{
		c = 'X';
	}
	cout << input_string << endl;

	return 0;
}
