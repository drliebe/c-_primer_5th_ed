#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using std::vector; 
using std::sort;

class Sales_data
{
public:
	Sales_data() = default;
	Sales_data(std::string s, unsigned int us, double rev);
	std::string isbn();
	Sales_data &operator+=(const Sales_data &rhs);
	friend Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs);	
	friend 	std::ostream &operator<<(std::ostream &os, const Sales_data &sd);
	friend 	std::istream &operator>>(std::istream &is, Sales_data &sd);
	
private: 
	std::string bookNo;
	unsigned int units_sold = 0;
	double revenue = 0.0;
};

Sales_data::Sales_data(std::string s, unsigned int us, double rev) : bookNo(s), units_sold(us), revenue(rev)
{

}

std::string Sales_data::isbn()
{
	return bookNo;
}

bool compareIsbn(Sales_data &sd1, Sales_data &sd2)
{
	return sd1.isbn() < sd2.isbn();

}

Sales_data &Sales_data::operator+=(const Sales_data &rhs)
{
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}

Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs)
{
	Sales_data sum = lhs;
	sum += rhs;
	return sum;
}

std::ostream &operator<<(std::ostream &os, const Sales_data &sd)
{
	os << sd.bookNo << " " << sd.units_sold << " " << sd.revenue;

}


std::istream &operator>>(std::istream &is, Sales_data &sd)
{
	is >> sd.bookNo >> sd.units_sold >> sd.revenue;
	if (!is)
		sd = Sales_data();

	return is;
}

int main ()
{
	vector<Sales_data> vecSD{
				Sales_data("123",1,9.99),
				Sales_data("78", 1, 19.99),
				Sales_data("456",2,15.00),
				Sales_data("9", 4, 36.00)};
	
	sort(vecSD.begin(), vecSD.end(), [] (Sales_data &sd1, Sales_data &sd2) {return sd1.isbn() < sd2.isbn();});

	for (auto sd : vecSD)
	{
		std::cout << sd << std::endl;		
		//std::cout << sd.isbn() << std::endl;
	}

	Sales_data temp = vecSD[0]+vecSD[1];

	return 0;
}
