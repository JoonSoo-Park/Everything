#ifndef DERIVEDE2M_H
#define DERIVEDE2M_H
#include "./Base.h"
#include <string>

class DerivedE2M : public Base{
public:
	explicit DerivedE2M(const char c);
	~DerivedE2M();
	DerivedE2M(const DerivedE2M&) = delete;
	DerivedE2M& operator=(const DerivedE2M&) = delete;

	bool translate(const char) override;
private:
	std::string _input;
	std::string _output;

	void erase() override;
	void eraseInput();
	void eraseOutput();
	void print() const;
	void makeRes(const char, const std::string&);
};

#endif
