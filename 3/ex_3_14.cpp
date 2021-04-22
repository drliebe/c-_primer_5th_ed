#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;
using std::endl;

int main()
{
	vector<int> integer_list;
	int input_integer = 0;
	
	while(cin >> input_integer)
	{
		integer_list.push_back(input_integer);
	}

	cout << "Vector Size" << integer_list.size() << endl;

	return 0;
}
