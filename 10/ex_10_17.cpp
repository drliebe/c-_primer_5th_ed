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
		std::cout << sd.isbn() << std::endl;
	}

	return 0;
}
