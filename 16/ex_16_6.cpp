#include <iostream>

template <typename T, unsigned N>
T* begin_josh(T (&array)[N])
{
	return &array[0];
}


template <typename T, unsigned N>
T* end_josh(T (&array)[N])
{
	return &array[N];
}


int main()
{
	int arr[6] = {1,2,3,4,5,6};

	int *pbeg;
	int *pend;

	pbeg = begin_josh(arr);
	pend = end_josh(arr);

	std::cout << *pbeg << std::endl;
	std::cout << *pend << std::endl;
	std::cout << *(--pend) << std::endl;

	return 0;
}
