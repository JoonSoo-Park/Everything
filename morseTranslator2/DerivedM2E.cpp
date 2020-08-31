#include <iostream>
#include "./DerivedM2E.h"
#include "./Code.h"

using std::string;

DerivedM2E::DerivedM2E(const char c) :
	_input(), _output(), _word()
{ 
	// std::cout << "Derived Morse -> Eng Constructor\n";
}

DerivedM2E::~DerivedM2E()
{
	// std::cout << "Derived Morse -> Eng Destructor\n";
}

bool DerivedM2E::translate(const char ch)
{
	if (ch == ' ') {
		const auto pos = code2.find(_word);
		if (pos != code2.end()) {
			makeRes(pos->second);
		}
	}
	else if (ch == 127) {
		erase();
	} 
	else {
		_word += ch;
	}
	printRes();

	return !(_input.empty() && _word.empty());
}

// erase input + output string or word depending on word size
void DerivedM2E::erase()
{
	if (_word.empty()){
		eraseOutput();
		eraseInput();
	}
	else {
		_word = string(_word.begin(), _word.end() - 1);
	}
}

// erase output string
void DerivedM2E::eraseOutput()
{
	if (_output.size() != 1)
		_output = string(_output.begin(), _output.end() - 1);
	else
		_output = "";
}

// erase input string
void DerivedM2E::eraseInput()
{
	// erase one character from input
	if (_input.back() == ' ')
		_input = string(_input.begin(), _input.end() - 1);

	auto p = _input.end() - 1;
	while (p != _input.begin() && !isspace(*p)) {
		--p;
	}

	if (p == _input.begin())  {
		_word = _input;
		_input = "";
	}
	else  {
		_word = string (p + 1, _input.end());
		_input = string(_input.begin(), p);
	}
}

// make temp string to print, then call print()
void DerivedM2E::printRes()
{
	string temp(_input);
	temp += ' ';
	temp += _word;
	const auto s = code2[_word];

	print(temp, s);
}

// prints input and output + currently typing string
void DerivedM2E::print(string& tempIn, const char tempOut)
{
	using std::cout;

	system("clear");
	cout << tempIn << '\n';
	cout << _output << tempOut;
}

void DerivedM2E::makeRes(const char c)
{
	_input += _word;
	_input += ' ';
	_output += c;
	_word = "";
}
