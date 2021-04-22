#include <iostream>
#include <string>
#include <vector>

using std::vector;
using std::cin;
using std::cout;
using std::endl;

int main()
{
	vector<int> integer_list(10);
	int input_integer = 0;
	for(auto &i : integer_list)
	{
		cout << "Enter integer: " << endl;
		cin >> input_integer;
		i = input_integer;
	}

	for(auto it = integer_list.begin(); it != integer_list.end(); ++it)
	{
		*it = (*it)*2;
	}

	for(auto it2 = integer_list.begin(); it2 != integer_list.end(); ++it2)
	{
		cout << *it2 << endl;
	}

	return 0;
}
