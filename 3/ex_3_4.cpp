#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;

int main()
{

	string s1;
	string s2;
	cin >> s1 >> s2;
/*	if (s1 == s2)
	{
		cout << "Strings are equal" << std::endl;
	}
	else if (s1 > s2) 
	{
		cout << "string 1 is larger" << std::endl;
	}
	else
	{
		cout << "string 2 is larger" << std::endl;
	}
*/
	if (s1.size() == s2.size())
	{
		cout << "Strings are equal length" << std::endl;
	}
	else if (s1.size() > s2.size()) 
	{
		cout << "string 1 is longer" << std::endl;
	}
	else
	{
		cout << "string 2 is longer" << std::endl;
	}


	return 0;
}
