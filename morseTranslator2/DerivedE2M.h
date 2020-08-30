#ifndef DERIVEDE2M_H
#define DERIVEDE2M_H
#include "./Base.h"
#include <string>

class DerivedE2M : public Base{
public:
	explicit DerivedE2M(char c);
	~DerivedE2M();

	bool translate(char) override;

	void erase();
	void print() const;
	void makeRes(char, std::string);
private:
	std::string _input;
	std::string _output;
};

#endif
