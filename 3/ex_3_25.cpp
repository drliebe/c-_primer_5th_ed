#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;
using std::endl;

int main()
{
	vector<unsigned int> scores(11, 0);
	unsigned int grade = 0;
	while(cin >> grade)
	{
		if (grade <= 100)
		{
			++(*(scores.begin()+(grade/10)));
		}
	}

	for(auto i : scores)
	{
		cout << i << endl;
	}

	return 0;
}
