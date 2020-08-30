#ifndef DERIVEDM2E_H
#define DERIVEDM2E_H
#include "./Base.h"
#include <string>

class DerivedM2E : public Base{
public:
	explicit DerivedM2E(char c);
	~DerivedM2E();

	bool translate(char) override;

	void erase();
	void print(std::string&, char);
	void printRes();
	void makeRes(char);
private:
	std::string _input;
	std::string _output;
	std::string _word;
};

#endif
