#include <iostream>
#include <string>

using std::string;

int main()
{
	string s("ab2c3d7R4E6");

	string numeric{"0123456789"};
	string alpha{"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};

	string::size_type i = 0;
	while( (i=s.find_first_of(numeric,i)) != string::npos)
	{
		std::cout << s[i] << " ";
		++i;
	}
	std::cout << std::endl;


	string::size_type j = 0;
	while( (j=s.find_first_of(alpha,j)) != string::npos)
	{
		std::cout << s[j] << " ";
		++j;
	}
	std::cout << std::endl;

	std::cout << std::endl << "Using first_not_of: " << std::endl;

	string::size_type k = 0;
	while( (k=s.find_first_not_of(alpha,k)) != string::npos)
	{
		std::cout << s[k] << " ";
		++k;
	}
	std::cout << std::endl;


	string::size_type l = 0;
	while( (l=s.find_first_not_of(numeric,l)) != string::npos)
	{
		std::cout << s[l] << " ";
		++l;
	}
	std::cout << std::endl;


	return 0;
}
