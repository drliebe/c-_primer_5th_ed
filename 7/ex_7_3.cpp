#include <iostream>
#include <string>

class Sales_data
{
public: 
	std::string isbn() const {return bookNo;}	
	Sales_data &combine(const Sales_data &rhs);

	std::string bookNo;
	unsigned int units_sold = 0;
	double revenue = 0.0;
};


Sales_data &Sales_data::combine(const Sales_data &rhs)
{
	revenue += rhs.revenue;
	units_sold += rhs.units_sold;
	return *this;
};

int main ()
{
	Sales_data total;

	if (std::cin >> total.bookNo >> total.units_sold >> total.revenue)
	{
		Sales_data trans;
		while (std::cin >> trans.bookNo >> trans.units_sold >> trans.revenue)
		{
			if (total.isbn() == trans.isbn())
			{
				total.combine(trans);
			}
			else
			{
				std::cout << total.isbn() << " " << total.units_sold << " " << total.revenue << std::endl;
				total = trans;

			}
		}
		std::cout << total.isbn() << " " << total.units_sold << " " << total.revenue << std::endl;

	} 
	else
	{
		std::cerr << "No data?!" <<std::endl;
		return -1;
	}

	return 0;
}
