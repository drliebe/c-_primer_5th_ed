#include <iostream>



int main()
{
	constexpr size_t rowCnt = 3, colCnt=4;
	int ia[rowCnt][colCnt] = 
	{	
		{0,1,2,3},
		{4,5,6,7},
		{8,9,10,11}
	};

	for(int (*row)[4] : ia)
	{
		for(int column : row)
		{
			std::cout << *column << std::endl;
		}
	}


	return 0;
}
