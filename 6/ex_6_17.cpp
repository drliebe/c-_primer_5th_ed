#include <iostream>
#include <string>
#include <cctype>

using std::string;

bool contains_caps(const string s)
{
	for(auto c : s)
	{
		if(isupper(c))
			return true;
	}
	return false;
}


void remove_caps(string &s)
{
	for(auto &c : s)
	{
		if(isupper(c))
			c = tolower(c);
	}
	return;
}


int main()
{
	string s1 = "Everybody have a GOOD time!";
	std::cout << s1 << std::endl << " contains_caps() : " << contains_caps(s1) << std::endl;
	remove_caps(s1);
	std::cout << " after remove_caps() : " << s1 << std::endl;

	return 0;
}
