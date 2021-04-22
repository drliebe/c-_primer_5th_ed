#include <iostream>

template <typename T, unsigned N>
void print_josh(T (&arr)[N])
{
	for(int i=0; i<N; ++i)
	{
		std::cout << arr[i] << std::endl;
	}
	return;
}


int main()
{
	constexpr unsigned array_size = 6;	//without constexpr this won't work, array's size must be fixed at compile time. 	
	int array[array_size] = {1,2,3,4,5,6};
	int array2[3] = {1,2,3};
	double array3[2] = {1.0, 2.0};
	std::string array4[4] = {"hello", "there", "josh", "finish"};
	print_josh(array);
	print_josh(array2);
	print_josh(array3);
	print_josh(array4);

	return 0;
}
