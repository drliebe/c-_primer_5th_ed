#include <iostream>
#include <string>

using std::string;

char* concatenate_literals(char *p1, int n1, char *p2, int n2)
{
	int n = n1 + n2;
	char *p = new char[n+1];

	for(int i=0; i<n1; i++)
	{
		*(p+i) = *(p1+i);
	}
	for(int j=0; j<n2; j++)
	{
		*(p+j+n1) = *(p2+j);
	}
	*(p+n1+n2) = '\n';

	return p;
}

string* concatenate_strings(string &s1, string &s2)
{
	return new string(s1+s2);
}

int main()
{
	char c1[3] = {'a','b','c'};
	char c2[3] = {'d','e','f'};

	char *pc = concatenate_literals(c1, 3, c2, 3);

	for(int i=0; i<6; i++)
	{
		std::cout << *(pc+i);
	}
	std::cout << std::endl;

	string s1 = "abc";
	string s2 = "def";

	string *ps = concatenate_strings(s1, s2);	

	std::cout << *ps << std::endl;

	delete [] pc;
	delete ps;


	return 0;
}
