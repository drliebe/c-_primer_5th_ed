#include <iostream>
#include <bitset>

int main()
{
	std::bitset<32> b1("1000000010000100101110");
	std::bitset<32> b2;

	b2.set(1);
	b2.set(2);
	b2.set(3);
	b2.set(5);
	b2.set(8);
	b2.set(13);
	b2.set(21);

	return 0;
}
