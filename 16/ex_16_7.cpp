#include <iostream>
#include <string>

template <typename T, unsigned N>
constexpr unsigned size_josh(T (&arr)[N])
{
	return N;
}


int main()
{
	int arr1[6] = {1,2,3,4,5,6};
	double arr2[3] = {1.0, 2.0, 3.0};
	std::string arr3[2] = {"hello", "world"};

	std::cout << size_josh(arr1) << " " << size_josh(arr2) << " " << size_josh(arr3) << std::endl;

	return 0;
}
