#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <memory>
#include <algorithm>

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
	virtual Quote *clone() const & {return new Quote(*this);}
	virtual Quote *clone() && {return new Quote(std::move(*this));}
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
	Bulk_quote *clone() const & {return new Bulk_quote(*this);}
	Bulk_quote *clone() && {return new Bulk_quote(std::move(*this));}
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


class Basket
{
public:
	void add_item(const Quote &sale) {items.insert(std::shared_ptr<Quote>(sale.clone()));}
	void add_item(Quote &&sale) {items.insert(std::shared_ptr<Quote>(std::move(sale).clone()));}
	double total_receipt(std::ostream &os) const;
private:
	static bool compare(const std::shared_ptr<Quote> &lhs, const std::shared_ptr<Quote> &rhs) 
		{return  lhs->isbn() < rhs->isbn();}
	std::multiset<std::shared_ptr<Quote>, decltype(compare)*> items{compare};
};

double Basket::total_receipt(std::ostream &os) const
{
	double sum = 0.0;
	for (auto iter = items.cbegin(); iter != items.cend(); iter = items.upper_bound(*iter))
	{
		sum += print_total(os, **iter, items.count(*iter));
	} 
	os << "Total Sale: " << sum << std::endl;
	return sum;
}

int main()
{
	/*
	std::vector<std::shared_ptr<Quote>> vq;
	vq.push_back(std::make_shared<Bulk_quote>("123", 9.99, 10, 0.25));
	vq.push_back(std::make_shared<Bulk_quote>("456", 12.99, 10, 0.25));
	vq.push_back(std::make_shared<Bulk_quote>("789", 14.99, 10, 0.25));
	vq.push_back(std::make_shared<Bulk_quote>("975", 19.99, 10, 0.25));
	
	double sum = 0;
	for (auto q : vq)
	{
		sum += q->net_price(10);
	}

	std::cout << sum << std::endl;
	*/

	Basket bskt;
	for(int i=0; i<10; i++)
	{
		bskt.add_item(Bulk_quote("123", 9.99, 10, 0.25));
		bskt.add_item(Bulk_quote("456", 12.99, 10, 0.25));
		bskt.add_item(Bulk_quote("789", 14.99, 10, 0.25));
		bskt.add_item(Bulk_quote("975", 19.99, 10, 0.25));	
	}
	bskt.total_receipt(std::cout);

	return 0;
}
