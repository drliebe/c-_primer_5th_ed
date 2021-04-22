#include <iostream>
#include <string>

class Account
{
public:
	void calculate() {amount += amount*interestRate;}
	static double rate();
	static void rate(double r);
private:
	std::string owner;
	double amount;
	static double interestRate;
	static double initRate();
	static constexpr int period = 30;
	double daily_tbl[period];

};

double Account::rate()
{
	return interestRate;
}

void Account::rate(double r)
{
	interestRate = r;
};

double Account::initRate()
{
	return 0.05;
}

double Account::interestRate = 0.03;

int main()
{
	Account a1;

	std::cout << a1.rate() << std::endl;
	a1.rate(0.07);
	std::cout << a1.rate() << std::endl;

	return 0;
}
