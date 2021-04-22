#include <iostream>

int sequence()
{
	static int i = 0;
	return i++;

}



int main()
{
	std::cout << sequence() << std::endl;
	std::cout << sequence() << std::endl;
	std::cout << sequence() << std::endl;
	std::cout << sequence() << std::endl;
	std::cout << sequence() << std::endl;

	return 0;
}
