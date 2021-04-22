#include <iostream>
#include <string>
#include <sstream>

using std::string;
using std::ostream;

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


template <typename T>
ostream &print(ostream &os, const T &t)
{
	return os << t;
}

template <typename T, typename... Args>
ostream &print(ostream &os, const T &t, const Args&... rest)
{
	os << t << ", ";
	return print(os, rest...);
}


template <typename... Args>
ostream &errorMsg(ostream &os, const Args&... rest)
{
	return print(os, debug_rep(rest)...);
}

int main()
{
	int i=0;
	long j=1;
	unsigned int k=2;
	double l = 3;
	long double m = 4;
	errorMsg(std::cout, i, j, k, l, m);
	return 0;
}
