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

/*	for(auto &c : input_string)
	{
		c = 'X';
	}

*/
	int i = 0;
	while(i< input_string.size())
	{
		input_string[i] = 'X';
		++i;
	}

/*	for(int i = 0; i < input_string.size(); ++i)
	{
		input_string[i] = 'X';
	}
*/

	cout << input_string << endl;

	return 0;
}
