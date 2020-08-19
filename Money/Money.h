#ifndef MONEY_H
#define MONEY_H
#include <iostream>

enum class CURRENCY {
	NOT_SPECIFIED = 0,
	CAD,		// Canada Dollar
	CNY,		// China Yuan
	EUR,		// Euro
	GBP,		// Great Britian Pound
	JPY,		// Japanese Yen
	KRW,		// Korea Won
	USD			// US Dollar
};

class Money;

bool operator== (const Money&, const Money&);
bool operator== (const Money&, const double&);
bool operator== (const double&, const Money&);

bool operator!= (const Money&, const Money&);
bool operator!= (const Money&, const double&);
bool operator!= (const double&, const Money&);

bool operator> (const Money&, const Money&);
bool operator> (const Money&, const double&);
bool operator> (const double&, const Money&);

bool operator< (const Money&, const Money&);
bool operator< (const Money&, const double&);
bool operator< (const double&, const Money&);

bool operator>= (const Money&, const Money&);
bool operator>= (const Money&, const double&);
bool operator>= (const double&, const Money&);

bool operator<= (const Money&, const Money&);
bool operator<= (const Money&, const double&);
bool operator<= (const double&, const Money&);

Money operator+ (const Money&, const Money&);
Money operator+ (const Money&, const double&);
Money operator+ (const double&, const Money&);

Money operator- (const Money&, const Money&);
Money operator- (const Money&, const double&);

// return true if same currency, or currency is not defined
inline bool Check_currency(const Money&, const Money&);
inline bool Check_amount(const double&, const double&);
inline void minusHelper(Money&, const double&, const double&);

class Money {
	friend std::istream& operator>>(std::istream&, Money&);
	friend std::ostream& operator<<(std::ostream&, const Money&);
	friend Money operator- (const Money&, const Money&);
	friend Money operator- (const Money&, const double&);
	friend Money operator- (const double&, const Money&);
	friend void minusHelper(Money&, const double&, const double&);
	public:
		explicit Money(CURRENCY currency, double amount = 0) 			
			: _currency(currency), _amount(amount) { }
		// copy constructor
		Money(const Money& money) :
			_currency(money._currency), _amount(money._amount) { } 
		// copy assignment
		Money& operator=(const Money&);
		Money& operator=(const double&);
		// operator +=
		Money& operator+=(const Money&);
		Money& operator+=(const double&);
		Money& operator-=(const Money&);
		Money& operator-=(const double&);
		
		inline const double Amount() const {
			return _amount;
		}

		inline CURRENCY Currency() const {
			return _currency;
		}

		inline void Clear() {
			_amount = 0.0;
		}

		operator double() const {
			std::cout << "operator double()\n";
			return _amount;
		}

		operator const double() const {
			return _amount;
		}

		operator int() const {
			return static_cast<int> (_amount);
		}

		operator const int() const {
			return static_cast<int> (_amount);
		}

	private:
		inline void Copy(const double& money) {
			_amount = money;
		}
		inline void Copy(const Money& money) {
			_amount = money._amount;
			_currency = money._currency;
		}

	private:
		CURRENCY _currency;
		double _amount;
};

#endif
