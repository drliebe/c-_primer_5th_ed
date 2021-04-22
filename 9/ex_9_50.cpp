#include <iostream>
#include <vector>
#include <string>


using std::vector;
using std::string;

int main()
{
	vector<string> s{"1","2","3","4","5"};

	int sum = 0;

	for(auto si : s)
	{
		sum+=stoi(si);
	}

	std::cout << "Sum: " << sum << std::endl;


	double dsum = 0.0;

	for(auto si : s)
	{
		dsum+=stod(si);
	}

	std::cout << "Sum: " << dsum << std::endl;

	return 0;
}
