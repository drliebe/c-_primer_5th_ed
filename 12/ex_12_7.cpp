#include <iostream>
#include <vector>
#include <memory>

using std::vector;
using std::shared_ptr;
using std::make_shared;

shared_ptr<vector<int>> create_vector()
{
	return make_shared<vector<int>>();
}

void read_input(shared_ptr<vector<int>> vec)
{
	int input_i;
	while (std::cin >> input_i)
	{
		vec->push_back(input_i);
	}
	return;
}

void print_vector(shared_ptr<vector<int>> vec)
{
	for(auto i : *vec)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;

	return;
}

int main()
{
	shared_ptr<vector<int>> vi = create_vector();
	read_input(vi);
	print_vector(vi);

	return 0;
}

