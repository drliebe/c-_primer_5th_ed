#include <iostream>
#include <string>

using std::istream;
using std::ostream;

class Sales_data
{
public: 
	std::string isbn() const {return bookNo;}	
	Sales_data &combine(const Sales_data &rhs);
	double avg_price() const {return revenue/units_sold;}

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


Sales_data add(const Sales_data lhs, const Sales_data rhs)
{
	Sales_data sum = lhs;
	sum.combine(rhs);
	return sum;
};

istream &read(istream &is, Sales_data &item)
{
	double price = 0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price * item.units_sold;
	return is;
};

ostream &print(ostream &os, const Sales_data &item)
{
	os << item.isbn() << " " << item.units_sold << " " 
		<< item.revenue << " " << item.avg_price();

}

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
