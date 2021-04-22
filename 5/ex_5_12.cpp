#include <iostream>
#include <string>


int main()
{
	std::string input_string;
	int aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;
	int blankCnt = 0, tabCnt = 0, newlineCnt = 0;
	int ffCnt = 0, flCnt = 0, fiCnt = 0;

	while(getline(std::cin,input_string))
	{
		bool previous_letter_f = false;		
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

			if (c == 'l')
			{
				if (previous_letter_f)
					++flCnt;

			}	

			if (c == 'i')
			{
				if (previous_letter_f)
					++fiCnt;

			}

			if (c == 'f')
			{
				if (previous_letter_f)
					++ffCnt;

				previous_letter_f = true;
			} 
			else
			{
				previous_letter_f = false;
			}
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
	std::cout << "ffCnt: " << ffCnt << std::endl;
	std::cout << "flCnt: " << flCnt << std::endl;
	std::cout << "fiCnt: " << fiCnt << std::endl;

	return 0;
}
