#include <iostream>
#include <memory>
#include "./Base.h"
#include "./DerivedE2M.h"
#include "./DerivedM2E.h"
#include "./_getch.h"

void func()
{
	using std::unique_ptr;

	char c;
	c = _getch();
	
	unique_ptr<Base> translator1 = nullptr;
	if (c == '.' || c == '-') {
		translator1 = std::make_unique<DerivedM2E>(c);
		std::cout << "Morse -> English\n";
	}
	else if (c == 127) {
		std::cout << "## Nothing to Erase ##\n";
	}
	else {
		translator1 = std::make_unique<DerivedE2M>(c);
		std::cout << "English -> Morse\n";
	} 

	if (translator1 != nullptr) {
		do {
			if (!translator1->translate(c))
				break;
			c = _getch();
		} while (true);
	}
}

int main()
{
	while (true) {
		func();
	}
}
