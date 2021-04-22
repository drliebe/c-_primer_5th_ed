#include <iostream>
#include <vector>

using std::vector;

int main()
{
	vector<int> int1 = {1,2,3,4,5};
	vector<int> int2 = {1,2,3,4,5,6};

	bool prefix_of = true;

	if(int1.size() == int2.size())
	{
		for(decltype(int1.size()) i = 0; i != int1.size(); ++i)
		{
			if (int1[i] != int2[i])
				prefix_of = false;
		}	
	}
	else if (int1.size() > int2.size())
	{
		for(decltype(int2.size()) i = 0; i != int2.size(); ++i)
		{
			if (int1[i] != int2[i])
				prefix_of = false;
		}
	}
	else if (int1.size() < int2.size())
	{
		for(decltype(int1.size()) i = 0; i != int1.size(); ++i)
		{
			if (int1[i] != int2[i])
				prefix_of = false;
		}

	}

	std::cout << prefix_of << std::endl;

	return 0;
}
