#include <iostream>
#include <fstream>
#include <string>

class Sales_data
{
public: 
	std::string bookNo;
	unsigned int units_sold = 0;
	double revenue = 0.0;
};


int main (int argv, char** argc)
{
	std::string filename(argc[1]);
	std::ifstream ifs;
	ifs.open(filename);

	if (!ifs)
	{
		std::cout << "Error Opening " << filename << std::endl;
	}	

	Sales_data total;

	if (ifs >> total.bookNo >> total.units_sold >> total.revenue)
	{
		Sales_data trans;
		while (ifs >> trans.bookNo >> trans.units_sold >> trans.revenue)
		{
			if (total.bookNo == trans.bookNo)
			{
				total.revenue = total.revenue + trans.revenue;
				total.units_sold = total.units_sold + trans.units_sold;
			}
			else
			{
				std::cout << total.bookNo << " " << total.units_sold << " " << total.revenue << std::endl;
				total = trans;

			}
		}
		std::cout << total.bookNo << " " << total.units_sold << " " << total.revenue << std::endl;

	} 
	else
	{
		std::cerr << "No data?!" <<std::endl;
		return -1;
	}

	return 0;
}
