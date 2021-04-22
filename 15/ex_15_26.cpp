#include <iostream>
#include <string>


class Quote
{
public:
	Quote() = default;
	Quote(const Quote &q);
	Quote(Quote &&q);
	Quote &operator=(const Quote &rhs);
	Quote &operator=(Quote &&rhs);
	Quote(const std::string &book, double sales_price) :
		bookNo(book), price(sales_price)  { }
	std::string isbn() const { return bookNo; }
	virtual double net_price(std::size_t n) const
		{ return n*price; }
	virtual void debug(std::ostream &os=std::cout) const;
	virtual ~Quote();
protected:
	double price;
private:
	std::string bookNo;
};

Quote::Quote(const Quote &q)
{
	if(this != &q)
	{
		price = q.price;
		bookNo = q.bookNo;
	}
	std::cout << "Quote(const Quote &q)" << std::endl;
}

Quote::Quote(Quote &&q)
{
	if(this != &q)
	{
		price = std::move(q.price);
		bookNo = std::move(q.bookNo);
		q.price = 0.0;
		q.bookNo = "";
	}
	std::cout << "Quote(Quote &&q)" << std::endl;
}


Quote &Quote::operator=(const Quote &rhs)
{
	if(this != &rhs)
	{
		price = rhs.price;
		bookNo = rhs.bookNo;
	}
	std::cout << "operator=(const Quote &rhs)" << std::endl;
	return *this;
}

Quote &Quote::operator=(Quote &&rhs)
{
	if(this != &rhs)
	{
		price = std::move(rhs.price);
		bookNo = std::move(rhs.bookNo);
		rhs.price = 0.0;
		rhs.bookNo = "";		
	}
	std::cout << "operator=(Quote &&rhs)" << std::endl;
	return *this;
}

Quote::~Quote()
{
	std::cout << "~Quote()" << std::endl;
}

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
	Bulk_quote(const Bulk_quote &b) : Disc_quote(b) { std::cout << "Bulk_quote(const Bulk_quote &b)" << std::endl; }
	Bulk_quote(Bulk_quote &&b) : Disc_quote(std::move(b)) { std::cout << "Bulk_quote(Bulk_quote &&b)" << std::endl; }
	Bulk_quote &operator=(const Bulk_quote &rhs);
	Bulk_quote &operator=(Bulk_quote &&rhs);
	~Bulk_quote() override { std::cout << "~Bulk_quote()" << std::endl; }
	double net_price(std::size_t cnt) const override;
	void debug(std::ostream &os=std::cout) const override;
protected:

private:
	
};

Bulk_quote::Bulk_quote(const std::string &book, double p, std::size_t qty, double disc) :
	Disc_quote(book, p, qty, disc) { }


Bulk_quote &Bulk_quote::operator=(const Bulk_quote &rhs)
{
	if (this != &rhs)
	{
		Disc_quote::operator=(rhs);
	}
	std::cout << "operator=(const Bulk_quote &rhs)" << std::endl;
	return *this;
}

Bulk_quote &Bulk_quote::operator=(Bulk_quote &&rhs)
{
	if (this != &rhs)
	{
		Disc_quote::operator=(std::move(rhs));
	}	
	std::cout << "operator=(Bulk_quote &&rhs)" << std::endl;
	return *this;
}


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
	//Quote q1("123", 9.99);
	//Quote q2(q1);
	//Quote q3(std::move(q1));
	//Quote q4;
	//q4 = q1;
	//Quote q5;
	//q5 = std::move(q1);

	Bulk_quote b1("456", 12.50, 5, 0.1);
	//Bulk_quote b2(b1);
	//Bulk_quote b3(std::move(b1));
	//Bulk_quote b4;
	//b4 = b1;
	Bulk_quote b5;
	b5 = std::move(b1);

	return 0;
}
