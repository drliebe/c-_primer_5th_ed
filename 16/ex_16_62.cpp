#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <unordered_set>

using std::vector; 
using std::sort;



class Sales_data
{
public:
	Sales_data() = default;
	Sales_data(std::string s, unsigned int us, double rev);
	std::string isbn();
	Sales_data &operator=(const std::string &rhs);
	Sales_data &operator+=(const Sales_data &rhs);
	operator std::string() {return bookNo;}
	operator double() {return revenue;}
	friend bool operator==(const Sales_data &lhs, const Sales_data &rhs);
	friend Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs);	
	friend std::ostream &operator<<(std::ostream &os, const Sales_data &sd);
	friend std::istream &operator>>(std::istream &is, Sales_data &sd);
	friend class std::hash<Sales_data>;
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

Sales_data &Sales_data::operator=(const std::string &rhs)
{
	bookNo = rhs;
	return *this;
}

Sales_data &Sales_data::operator+=(const Sales_data &rhs)
{
	/*
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this; 
	*/
	*this = *this + rhs;
	return *this;
}

bool operator==(const Sales_data &lhs, const Sales_data &rhs)
{
	if ((lhs.bookNo == rhs.bookNo) && (lhs.units_sold == rhs.units_sold) && (lhs.revenue == rhs.revenue))
		return true;
	return false;
}

Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs)
{
	/*
	Sales_data sum = lhs;
	sum += rhs;
	return sum;
	*/
	Sales_data sum = lhs;
	sum.units_sold += rhs.units_sold;
	sum.revenue += rhs.revenue;
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

namespace std {
template <> struct hash<Sales_data>
{
	typedef size_t result_type;
	typedef Sales_data argument_type;
	size_t operator()(const Sales_data &s) const;
};

size_t hash<Sales_data>::operator()(const Sales_data &s) const
{
	return hash<string>()(s.bookNo) ^
		hash<unsigned>()(s.units_sold) ^
		hash<double>()(s.revenue);
}

}


int main ()
{
	std::unordered_set<Sales_data>	SDSet;
	Sales_data sd1("123", 3, 29.97);
	Sales_data sd2("456", 2, 12.50);
	Sales_data sd3("789", 1, 9.50);

	SDSet.insert(sd1);
	SDSet.insert(sd2);
	SDSet.insert(sd3);

	for (auto sd : SDSet)
		std::cout << sd << std::endl;
	

	return 0;
}
