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

	cin >> input_string;

	for(auto c : input_string)
	{
		if(!std::ispunct(c))
		{
			output_string += c;	
		}
	}

	cout << output_string << endl;

	return 0;
}
