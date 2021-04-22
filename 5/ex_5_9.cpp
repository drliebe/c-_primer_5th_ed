#include <iostream>
#include <string>


int main()
{
	std::string input_string;
	int aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;

	while(std::cin >> input_string)
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
		}
	}
	std::cout << "Number of vowels: " << aCnt+eCnt+iCnt+oCnt+uCnt << std::endl;

	return 0;
}
