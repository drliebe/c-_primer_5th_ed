#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;

int main()
{
	vector<int> integer_inputs;
	int integer_input;
	while(cin >> integer_input)
	{
		integer_inputs.push_back(integer_input);
	}
	
	cout << "Sum of adjacent elements: " << endl;

	for(auto it = integer_inputs.begin(); it!=(integer_inputs.end()-1); ++it)
	{
		cout << (*it)+(*(it+1)) << endl;
	}


	cout << "Sum of first/last second/second-to-last elements: " << endl;

	for(decltype(integer_inputs.size()) i = 0; i != integer_inputs.size(); ++i)
	{
		cout << *(integer_inputs.begin()+i) + *(integer_inputs.end()-1-i) << endl;
	}


	return 0;
}
