#include <iostream>
#include <string>

using std::istream;
using std::ostream;
using std::cout;
using std::cin;
using std::string;

class Sales_data
{
public: 
	Sales_data() = default;
	Sales_data(const string &s) : bookNo(s) { }
	Sales_data(const string &s, unsigned n, double p) :
		bookNo(s), units_sold(n), revenue(p*n) { }
	Sales_data(istream &is);
	string isbn() const {return bookNo;}	
	Sales_data &combine(const Sales_data &rhs);
	double avg_price() const {return (units_sold == 0) ? 0.0 : revenue/units_sold;}

	string bookNo;
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
	return os;
}

Sales_data::Sales_data(istream &is)
{
	read(is, *this);
}


int main ()
{
	Sales_data default_item;
	print(cout, default_item) << std::endl;

	Sales_data string_item("12345");
	print(cout, string_item) << std::endl;

	Sales_data compound_item("6543", 2, 13.50);
	print(cout, compound_item) << std::endl;

	Sales_data input_item(cin);
	print(cout, input_item) << std::endl;	
	
	return 0;
}

