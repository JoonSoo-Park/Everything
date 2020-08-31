#ifndef DERIVEDE2M_H
#define DERIVEDE2M_H
#include "./Base.h"
#include <string>

class DerivedE2M : public Base{
public:
	explicit DerivedE2M(char c);
	~DerivedE2M();
	DerivedE2M(const DerivedE2M&) = delete;
	DerivedE2M& operator=(const DerivedE2M&) = delete;

	bool translate(char) override;
private:
	std::string _input;
	std::string _output;

	void erase();
	void print() const;
	void makeRes(char, std::string);
};

#endif
