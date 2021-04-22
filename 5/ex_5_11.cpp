#include <iostream>
#include <string>


int main()
{
	std::string input_string;
	int aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;
	int blankCnt = 0, tabCnt = 0, newlineCnt = 0;

	while(getline(std::cin,input_string))
	{
		for(auto c: input_string)
		{
			if ((c == 'a') || (c == 'A'))
				++aCnt;
			if ((c == 'e') || (c == 'E'))
				++eCnt;
			if ((c == 'i') || (c == 'I'))
				++iCnt;
			if ((c == 'o') || (c == 'O'))
				++oCnt;
			if ((c == 'u') || (c == 'U'))
				++uCnt;
			if (c == ' ')
				++blankCnt;
			if (c == '\t')
				++tabCnt;
			if (c == '\n')
				++newlineCnt;
		}
	}
	std::cout << "aCnt: " << aCnt << std::endl;
	std::cout << "eCnt: " << eCnt << std::endl;
	std::cout << "iCnt: " << iCnt << std::endl;
	std::cout << "oCnt: " << oCnt << std::endl;
	std::cout << "uCnt: " << uCnt << std::endl;
	std::cout << "blankCnt: " << blankCnt << std::endl;
	std::cout << "tabCnt: " << tabCnt << std::endl;
	std::cout << "newlineCnt: " << newlineCnt << std::endl;

	return 0;
}
