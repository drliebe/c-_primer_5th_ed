#include <iostream>
#include <string>

using std::istream;
using std::ostream;
using std::cout;
using std::cin;
using std::string;

class Sales_data;
istream &read(istream &is, Sales_data &item);

class Sales_data
{
public: 
	Sales_data() : bookNo(""), units_sold(0), revenue(0.0)     { }
	Sales_data(const string &s) : bookNo(s)                    { }
	Sales_data(const string &s, unsigned n, double p) :
		bookNo(s), units_sold(n), revenue(p*n)             { }
	Sales_data(istream &is)                                    {read(is, *this); }
	string isbn() const                                        {return bookNo;}
	unsigned int quantity_sold() const			   {return units_sold;}
	double total_revenue() const                               {return revenue;}	
	Sales_data &combine(const Sales_data &rhs);
        double avg_price() const {return (units_sold == 0) ? 0.0 : revenue/units_sold;}
	
private:
	string bookNo;
	unsigned int units_sold = 0;
	double revenue = 0.0;

	friend istream &read(istream &is, Sales_data &item);
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
	os << item.isbn() << " " << item.quantity_sold() << " " 
		<< item.total_revenue() << " " << item.avg_price();
	return os;
}




int main ()
{
	Sales_data total(std::cin);
	if (std::cin)
	{
		Sales_data trans(std::cin);
		while (std::cin)
		{
			if (total.isbn() == trans.isbn())
			{
				total.combine(trans);
			}
			else
			{
				print(std::cout, total) << std::endl;
				total = trans;
			}
			read(std::cin, trans);
		}
		print(std::cout, total) << std::endl;
	}
	else
	{
		std::cerr << "No data?!" <<std::endl;
	}	

	return 0;
}

