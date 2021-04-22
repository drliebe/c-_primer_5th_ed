#include <iostream>
#include "Sales_item.h"

int main ()
{
	Sales_item first_item;
	Sales_item new_item;
	if (std::cin >> first_item)
	{
		while (std::cin >> new_item)
		{
			first_item += new_item;
		}

		std::cout << first_item << std::endl;
	}
	return 0;
}
