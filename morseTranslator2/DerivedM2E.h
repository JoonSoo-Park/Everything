#ifndef DERIVEDM2E_H
#define DERIVEDM2E_H
#include "./Base.h"
#include <string>

class DerivedM2E : public Base{
public:
	explicit DerivedM2E(char c);
	~DerivedM2E();
	DerivedM2E(const DerivedM2E&) = delete;
	DerivedM2E& operator=(const DerivedM2E&) = delete;

	bool translate(char) override;
private:
	std::string _input;
	std::string _output;
	std::string _word;

	void erase();
	void print(std::string&, char);
	void printRes();
	void makeRes(char);
};

#endif
