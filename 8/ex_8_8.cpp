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
	if (argv != 3)
	{
		std::cout << "Incorrect number of arguments. Need both input and output filenames."
			<< std::endl;
	}

	std::string input_filename(argc[1]);
	std::string output_filename(argc[2]);

	std::ifstream ifs;
	ifs.open(input_filename);
	if (!ifs)
	{
		std::cout << "Error Opening " << input_filename << std::endl;
	}	

	std::ofstream ofs;
	ofs.open(output_filename, std::ofstream::app);
	if (!ofs)
	{
		std::cout << "Error Opening " << output_filename << std::endl;
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
				ofs << total.bookNo << " " << total.units_sold << " " << total.revenue << std::endl;
				total = trans;

			}
		}
		ofs << total.bookNo << " " << total.units_sold << " " << total.revenue << std::endl;

	} 
	else
	{
		std::cerr << "No data?!" <<std::endl;
		return -1;
	}

	return 0;
}
