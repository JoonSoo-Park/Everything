#include <iostream>
#include "./DerivedE2M.h"
#include "./Code.h"

using std::string;

DerivedE2M::DerivedE2M(char c) :
	_input(), _output() 
{
	//std::cout << "Derived English -> Morse Constructor\n";
}

DerivedE2M::~DerivedE2M()
{
	//std::cout << "Derived English -> Morse Destructor\n";
}

bool DerivedE2M::translate(char ch) 
{
	if (ch == 127) {
		erase();
		print();
	}
	else {
		auto pos = code1.find(ch);
		if (pos != code1.end()) {
			makeRes(ch, pos->second);
		}
	}

	return !_input.empty();
}

void DerivedE2M::erase()
{
	_input = std::string(_input.begin(), _input.end() - 1);

	auto pos = _output.end();
	int ct = 0;
	do {
		pos--;
		if (*pos == ' ' || *pos == '\\')
			ct++;
	} while (pos != _output.begin() && ct < 2);

	if (pos == _output.begin()) {
		_output = "";
	} 
	else {
		_output = std::string(_output.begin(), pos + 1);
	}
}

void DerivedE2M::print() const 
{
	using std::cout;

	system("clear");
	cout << _input << '\n';
	cout << _output << '\n';
}

void DerivedE2M::makeRes(char ch, string s)
{
	string t = s + ' ';
	_input += ch;
	_output += t;

	print();
}
