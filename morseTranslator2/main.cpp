#include <iostream>
#include <memory>
#include "./Base.h"
#include "./DerivedE2M.h"
#include "./DerivedM2E.h"
#include "./_getch.h"

void func()
{
	using std::unique_ptr;
	using std::make_unique;
	using std::cout;

	char c;
	c = _getch();
	
	unique_ptr<Base> translator = nullptr;
	if (c == '.' || c == '-') {
		translator = make_unique<DerivedM2E>(c);
		cout << "Morse -> English\n";
	}
	else if (c == 127) {
		cout << "## Nothing to Erase ##\n";
	}
	else if (c > 31 && c < 127){
		translator = make_unique<DerivedE2M>(c);
		cout << "English -> Morse\n";
	} 

	if (translator != nullptr) {
		do {
			if (!translator->translate(c))
				break;
			c = _getch();

			if (c == 27) { // ESC
				system("clear");
				break;
			}
		} while (true);
	}
}

int main()
{
	system("clear");

	while (true) {
		func();
	}
}
