#include <iostream>
#include <vector>

using std::vector;

int func_add(int i, int j)
{
	return i+j;
}

int func_subtract(int i, int j)
{
	return i-j;
}

int func_multiply(int i, int j)
{
	return i*j;
}

int func_divide(int i, int j)
{
	return i/j;
}


int main()
{

	vector<int (*)(int, int)> vec_of_funcs;

	std::cout << "works..." << std::endl;

	vec_of_funcs.push_back(&func_add);
	vec_of_funcs.push_back(&func_subtract);
	vec_of_funcs.push_back(&func_multiply);
	vec_of_funcs.push_back(&func_divide);

	std::cout << "still works... " << std::endl;

	

	return 0;
}
