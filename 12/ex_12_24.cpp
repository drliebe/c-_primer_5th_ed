#include <iostream>
#include <string>

using std::string;
using std::cin;

int main()
{
	char *pc = new char[10];
	int n = 0;
	char c;
	string input;

	while(cin >> input)
	{
		for(int k=0; k<input.size(); ++k)
		{
			*(pc+n) = input.at(k);		
			++n;
		}
	}

	for(int i=0; i<n; ++i)
	{
		std::cout << *(pc+i);
	}

	std::cout << std::endl;

	return 0;
}
