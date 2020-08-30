#include <iostream>
#include <string>
#include "./src.h"

using std::cout;
using std::cout;
using std::string;

void CLS()
{
	system("clear");
}

void printMsg()
{
	CLS();
	cout << "*** Morse Code Translator ***\n\n";
}

void printRes(string& input, string& output)
{
	printMsg();
	cout << '\n' << input << '\n';
	cout << output;
}
