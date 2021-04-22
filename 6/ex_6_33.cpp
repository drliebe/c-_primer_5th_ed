#include <iostream>
#include <vector>

using std::vector;

void print_vec(vector<int>::const_iterator it1, vector<int>::const_iterator it2)
{
	if (it1 != it2)
	{
		std::cout << (*it1) << std::endl;
		++it1;
		print_vec(it1, it2);
	}

	return;
}


int main()
{
	vector<int> vec1 = {1,2,3,4,5};

	print_vec(vec1.begin(), vec1.end());

	return 0;
}
