#include <iostream>
#include <string>


class Quote
{
public:
	Quote() = default;
	Quote(const std::string &book, double sales_price) :
		bookNo(book), price(sales_price)  { }
	std::string isbn() const { return bookNo; }
	virtual double net_price(std::size_t n) const
		{ return n*price; }
	virtual void debug(std::ostream &os=std::cout) const;
	virtual ~Quote() = default;
protected:
	double price;
private:
	std::string bookNo;
};

void Quote::debug(std::ostream &os) const
{
	os << "price: " << price << " bookNo: " << bookNo;
}

double print_total(std::ostream &os, const Quote &item, std::size_t n)
{
	double ret = item.net_price(n);
	os << "ISBN: " << item.isbn() << " # sold: " << n << 
		" total due: " << ret << std::endl;
	return ret;
}

class Bulk_quote : public Quote
{
public:
	Bulk_quote() = default;
	Bulk_quote(const std::string &book, double p, std::size_t qty, double disc);
	double net_price(std::size_t cnt) const override;
	void debug(std::ostream &os=std::cout) const override;
protected:

private:
	std::size_t min_qty = 0.0;
	double discount = 0.0;
};

Bulk_quote::Bulk_quote(const std::string &book, double p, std::size_t qty, double disc) :
	Quote(book, p), min_qty(qty), discount(disc) { }

double Bulk_quote::net_price(size_t cnt) const
{
	if (cnt >= min_qty)
		return cnt*(1-discount)*price;
	else
		return cnt*price;
}

void Bulk_quote::debug(std::ostream &os) const
{
	this->Quote::debug(os);
	os << " min_qty: " << min_qty << " discount: " << discount;
}


class Teaser_quote : public Quote
{
public:
	Teaser_quote() = default;
	Teaser_quote(const std::string &book, double p, std::size_t qty, double disc);
	double net_price(std::size_t cnt) const override;
	void debug(std::ostream &os=std::cout) const override;
protected:

private:
	std::size_t max_qty = 0.0;
	double discount = 0.0;
};

Teaser_quote::Teaser_quote(const std::string &book, double p, std::size_t qty, double disc) :
	Quote(book, p), max_qty(qty), discount(disc) { }

double Teaser_quote::net_price(size_t cnt) const
{
	if (cnt < max_qty)
		return cnt*(1-discount)*price;
	else
		return (cnt-max_qty)*price + max_qty*(1-discount)*price;
}

void Teaser_quote::debug(std::ostream &os) const
{
	this->Quote::debug(os);
	os << " max_qty: " << max_qty << " discount: " << discount;
}


int main()
{
	Quote q1("123", 9.99);
	Bulk_quote b1("456", 12.50, 5, 0.1);
	Teaser_quote t1("789", 16.00, 5, 0.25);
	print_total(std::cout, q1, 1);
	print_total(std::cout, b1, 10);
	print_total(std::cout, t1, 6);

	Quote *pq = &q1;
	pq->debug();
	std::cout << std::endl;
	pq = &b1;
	pq->debug();
	std::cout << std::endl;
	pq = &t1;
	pq->debug();
	std::cout << std::endl;

	return 0;
}
