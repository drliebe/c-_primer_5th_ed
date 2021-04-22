#include <iostream>

using std::ostream;

template <typename T> ostream &print(ostream&os, const T &t);

template <typename T, typename... Args>
ostream &print(ostream &os, const T &t, const Args&... rest)
{
	os << t << ", ";
	return print(os, rest...);
}

template <typename T>
ostream &print(ostream &os, const T &t)
{
	return os << t;
}

int main()
{
	int i = 0;
	long long j = 1;
	unsigned int k = 2;
	double l = 3;
	long double m = 4;

	print(std::cout, i);
	std::cout << std::endl;
	print(std::cout, i,j);
	std::cout << std::endl;
	print(std::cout, i, j, k);
	std::cout << std::endl;
	print(std::cout, i, j, k, l);
	std::cout << std::endl;
	print(std::cout, i, j, k, l, m);
	std::cout << std::endl;

	return 0;
}
