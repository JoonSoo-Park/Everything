#include <iostream>
#include "./Money.h"

Money& Money::operator=(const Money& money)
{
	if (Check_currency(*this, money) &&
			money._amount >= 0)
		Copy(money);
}

Money& Money::operator=(const double& money)
{
	if (money >= 0)
		Copy(money);
}

Money& Money::operator+=(const Money& money)
{
	if (this != &money) {
		if (Check_currency(*this, money))
			_amount += money._amount;
	}

	return *this;
}

Money& Money::operator+=(const double& money)
{
	_amount += money;	

	return *this;
}

Money& Money::operator-=(const Money& money)
{
	if (this != &money) {
		if (Check_currency(*this, money) &&
			Check_amount(money._amount))
			_amount -= money._amount;
	}

	return *this;
}

Money& Money::operator-=(const double& money)
{
	if (Check_amount(money))
		_amount -= money;
}

// operator+(Money + Money)
Money operator+(const Money& lhs, const Money& rhs)
{
	Money ret = lhs;
	ret += rhs;
	return ret;
}
Money operator+(const Money& lhs, const double& rhs)
{
	Money ret = lhs;
	ret += rhs;
	return ret;
}
Money operator+(const double& lhs, const Money& rhs)
{
	Money ret = rhs;
	ret += lhs;
	return ret;
}

// operator-(Money - Money)
Money operator-(const Money& lhs, const Money& rhs)
{
	Money ret = lhs;
	ret -= rhs;
	return ret;
}
Money operator-(const Money& lhs, const double& rhs)
{
	Money ret = lhs;
	ret -= rhs;
	return ret;
}
Money operator-(const double& lhs, const Money& rhs)
{
	Money ret = rhs;
	ret.Copy(lhs);
	ret -= rhs.Amount();
	return ret;
}

// operator<<
std::ostream& operator<<(std::ostream& os, const Money& money)
{
	os << money.Amount();

	return os;
}

// operator>>
std::istream& operator>>(std::istream& is, Money& money)
{
	money.Clear();

	is >> money._amount;

	is.clear();

	return is;
}

bool operator== (const Money& lhs, const Money& rhs)
{
	if (Check_currency(lhs, rhs))
		return lhs.Amount() == rhs.Amount();
	return false;
}
bool operator== (const Money& lhs, const double& rhs)
{
	return lhs.Amount() == rhs;
}
bool operator== (const double& lhs, const Money& rhs)
{
	return lhs == rhs.Amount();
}

bool operator!= (const Money& lhs, const Money& rhs)
{
	return !(lhs == rhs);
}
bool operator!= (const Money& lhs, const double& rhs)
{
	return !(lhs == rhs);
}
bool operator!= (const double& lhs, const Money& rhs)
{
	return !(lhs == rhs);
}

bool operator> (const Money& lhs, const Money& rhs)
{
	if (Check_currency(lhs, rhs))
		return lhs.Amount() > rhs.Amount();
	return false;
}
bool operator> (const Money& lhs, const double& rhs)
{
	return lhs.Amount() > rhs;
}
bool operator> (const double& lhs, const Money& rhs)
{
	return lhs > rhs.Amount();
}

bool operator< (const Money& lhs, const Money& rhs)
{
	if (Check_currency(lhs, rhs))
		return lhs.Amount() < rhs.Amount();
	return false;
}
bool operator< (const Money& lhs, const double& rhs)
{
	return lhs.Amount() < rhs;
}
bool operator< (const double& lhs, const Money& rhs)
{
	return lhs < rhs.Amount();
}

bool operator>= (const Money& lhs, const Money& rhs)
{
	if (Check_currency(lhs, rhs))
		return lhs.Amount() >= rhs.Amount();	
	return false;
}
bool operator>= (const Money& lhs, const double& rhs)
{
	return lhs.Amount() >= rhs;
}
bool operator>= (const double& lhs, const Money& rhs)
{
	return lhs >= rhs.Amount();
}

bool operator<= (const Money& lhs, const Money& rhs)
{
	if (Check_currency(lhs, rhs))
		return lhs.Amount() <= rhs.Amount();
	return false;
}
bool operator<= (const Money& lhs, const double& rhs)
{
	return lhs.Amount() <= rhs;
}
bool operator<= (const double& lhs, const Money& rhs)
{
	return lhs <= rhs.Amount();
}

bool Check_currency(const Money& lhs, const Money& rhs)
{
	return lhs.Currency() != rhs.Currency();
}
