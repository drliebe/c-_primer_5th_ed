#include <iostream>
#include <string>

using std::string;

bool str_subrange(const string &str1, const string &str2)
{
	if (str1.size() == str2.size())
		return str1 == str2;

	auto size = (str1.size() < str2.size())
		? str1.size() : str2.size();
	
	for (decltype(size) i = 0; i != size; ++i)
	{
		if (str1[i] != str2[i])
			return;
	}

}

int main()
{
	string s1 = "Hello There";
	string s2 = "Joshua Love";

	str_subrange(s1, s2);

	return 0;
}
