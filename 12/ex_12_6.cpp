#include <iostream>
#include <vector>

using std::vector;

vector<int>* create_vector()
{
	return new vector<int>;
}

void read_input(vector<int>* vec)
{
	int input_i;
	while (std::cin >> input_i)
	{
		vec->push_back(input_i);
	}
	return;
}

void print_vector(vector<int>* vec)
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
	vector<int> * vi = create_vector();
	read_input(vi);
	print_vector(vi);
	delete vi;

	return 0;
}

