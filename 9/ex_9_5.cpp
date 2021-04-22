#include <iostream>
#include <vector>
#include <string>

using std::vector;

vector<int>::iterator func2(vector<int>::iterator i1, vector<int>::iterator i2, int target_i)
{
	while (i1 != i2)
	{
		if (*i1 == target_i)
			return i1;
	
		++i1;
	}
	return i1;
}


int main(int argc, char** argv)
{
	vector<int> vi{1,2,3,4,5,6,7,8,9,10};
	std::string number_to_find = argv[1];
	int sought_int = std::stoi(number_to_find);

	vector<int>::iterator sought_it = func2(vi.begin(), vi.end(), sought_int);

	bool found(0);

	if (sought_it != vi.end())
		found = true;	

	std::cout << "sought_int=" << sought_int << " found? " << found << std::endl;

	return 0;
}
