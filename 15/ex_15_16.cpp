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


class Disc_quote : public Quote
{
public:
	Disc_quote() = default;
	Disc_quote(const std::string &book, double price, std::size_t qty, double disc) :
		Quote(book, price), quantity(qty), discount(disc) { }
	double net_price(std::size_t qty) const = 0;
	void debug(std::ostream &os=std::cout) const = 0;
protected:
	std::size_t quantity = 0;
	double discount = 0.0;
private:

};

class Bulk_quote : public Disc_quote
{
public:
	Bulk_quote() = default;
	Bulk_quote(const std::string &book, double p, std::size_t qty, double disc);
	double net_price(std::size_t cnt) const override;
	void debug(std::ostream &os=std::cout) const override;
protected:

private:
	
};

Bulk_quote::Bulk_quote(const std::string &book, double p, std::size_t qty, double disc) :
	Disc_quote(book, p, qty, disc) { }

double Bulk_quote::net_price(size_t cnt) const
{
	if (cnt >= quantity)
		return cnt*(1-discount)*price;
	else
		return cnt*price;
}

void Bulk_quote::debug(std::ostream &os) const
{
	this->Quote::debug(os);
	os << " min quantity: " << quantity << " discount: " << discount;
}


class Teaser_quote : public Disc_quote
{
public:
	Teaser_quote() = default;
	Teaser_quote(const std::string &book, double p, std::size_t qty, double disc);
	double net_price(std::size_t cnt) const override;
	void debug(std::ostream &os=std::cout) const override;
protected:

private:
};

Teaser_quote::Teaser_quote(const std::string &book, double p, std::size_t qty, double disc) :
	Disc_quote(book, p, qty, disc) { }

double Teaser_quote::net_price(size_t cnt) const
{
	if (cnt < quantity)
		return cnt*(1-discount)*price;
	else
		return (cnt-quantity)*price + quantity*(1-discount)*price;
}

void Teaser_quote::debug(std::ostream &os) const
{
	this->Quote::debug(os);
	os << " max quantity: " << quantity << " discount: " << discount;
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
