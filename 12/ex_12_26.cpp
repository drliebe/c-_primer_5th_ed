#include <iostream>
#include <string>
#include <memory>

using std::string;
using std::allocator;
using std::cin;

int main()
{
	size_t n = 10;
	allocator<string> alloc;
	string * const p = alloc.allocate(n);

	string *q = p;
	string s;

	while (cin >> s && q != p+n)
		*q++ = s;
	const size_t size = q - p;

	for(int i=0; i<size; ++i)
		std::cout << *(p+i) << std::endl;

	while (q != p)
		alloc.destroy(--q);

	alloc.deallocate(p,n);

	return 0;
}
