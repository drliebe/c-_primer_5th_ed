#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

int main()
{
	string input_string;
	string output_string;
	while(cin >> input_string)
	{
		output_string += input_string;
		output_string += ' ';
	}
	cout << output_string << endl;

	return 0;
}
