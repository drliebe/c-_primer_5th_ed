#include <iostream>
#include <string>

using std::string;


string replace_func(string s, string oldVal, string newVal)
{
	string::iterator it = s.begin();
	for(unsigned int k=0; k<s.size(); ++k)
	{
		bool match = true;		
		for(unsigned int i=0; i<oldVal.size(); ++i)
		{
			if (s[k+i] != oldVal[i])
			{
				match = false;
				break;
			}
		}

		if (match == true)
		{
			s.erase(k,oldVal.size());
			s.insert(k, newVal);
		}	
	}

	return s;
}

int main()
{
	string s("I am bored, though I am busy.");
	string old_s("though");
	string new_s("tho");

	s = replace_func(s,old_s,new_s);

	std::cout << s << std::endl;


	string s2("I am bored, through being busy.");
	string old_s2("through");
	string new_s2("thu");

	s2 = replace_func(s2,old_s2,new_s2);

	std::cout << s2 << std::endl;


	return 0;
}
