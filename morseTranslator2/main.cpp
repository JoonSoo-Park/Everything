#include <iostream>
#include "./Base.h"
#include "./DerivedE2M.h"
#include "./DerivedM2E.h"
#include "./_getch.h"

void func()
{
	char c;
	c = _getch();

	Base *translator = nullptr;
	if (c == '.' || c == '-') {
		translator = new DerivedM2E(c);	
		std::cout << "Morse -> English\n";
	}
	else if (c == 127) {
		std::cout << "## Nothing to Erase ##\n";
	}
	else {
		translator = new DerivedE2M(c);
		std::cout << "English -> Morse\n";
	} 
	
	if (translator != nullptr) {
		do {
			if (!translator->translate(c))
				break;
			c = _getch();
		} while (true);

		delete translator;
	}
}

int main()
{
	while (true) {
		func();
	}
}
