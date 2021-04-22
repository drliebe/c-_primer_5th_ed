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

	int add_result = vec_of_funcs[0](5,6);	
	int subtract_result = vec_of_funcs[1](5,6);	
	int multiply_result = vec_of_funcs[2](5,6);	
	int divide_result = vec_of_funcs[3](5,6);

	std::cout << "Add: " << add_result << std::endl;
	std::cout << "Subtract: " << subtract_result << std::endl;
	std::cout << "Multiply: " << multiply_result << std::endl;
	std::cout << "Divide: " << divide_result << std::endl;
	

	return 0;
}
