#include <iostream>
#include "Sales_item.h"

int main () 
{

	Sales_item current_item, new_item;
	if (std::cin >> current_item)
	{
		while (std::cin >> new_item)
		{
			if (current_item.isbn() == new_item.isbn())
			{
				current_item += new_item;
				
			}
			else
			{
				std::cout << current_item << std::endl;
				current_item = new_item;
			}
		}
		std::cout << current_item << std::endl;
	}
	return 0;
}
