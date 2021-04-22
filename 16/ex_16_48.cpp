#include <iostream>
#include <string>
#include <sstream>

using std::string;

// Forward Declarations
template <typename T> string debug_rep(const T &t);
template <typename T> string debug_rep(T *p);
string debug_rep(const string &s);
string debug_rep(char *p);
string debug_rep(const char *p);

// Definitions
template <typename T> string debug_rep(const T &t)
{
	std::ostringstream ret;
	ret << t;
	return ret.str();
}

template <typename T> string debug_rep(T *p)
{
	std::ostringstream ret;
	ret << "pointer: " << p;
	if (p)
		ret << " " << debug_rep(*p);
	else
		ret << " null pointer";
	return ret.str();
}

string debug_rep(const string &s)
{
	return '"' + s + '"';
}

string debug_rep(char *p)
{
	return debug_rep(string(p));
}

string debug_rep(const char *p)
{
	return debug_rep(string(p));
}


int main()
{
	string s = "Hello";
	char ca[6] = "There";
	const char ca2[5] = "Josh";
	double d = 3.14;

	std::cout << debug_rep(s) << std::endl;
	std::cout << debug_rep(ca) << std::endl;
	std::cout << debug_rep(ca2) << std::endl;
	std::cout << debug_rep(d) << std::endl;


	return 0;
}
