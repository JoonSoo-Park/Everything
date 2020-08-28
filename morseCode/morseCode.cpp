#include <algorithm>
#include "./Code.h"
#include "./_getch.h"
#include "./src.h"

std::string input = "";
std::string output = "";

const char delbuf[] = "\b";

// eng -> morse
void MakeRes(char c, std::string cc)
{
	std::string t = cc + ' ';
	input += c;
	output += t;

	printRes(input, output);
}

// morse -> eng
void MakeRes(std::string c, char cc)
{
	std::string t(1, cc);
	c += ' ';
	input += c;
	output += t;

	printRes(input, output);
}

void eraseEnglishToMorse()
{
	if (input.size() >= 1) {
		input = std::string(input.begin(), input.end() - 1);
	}

	auto pos = output.end();
	int ct = 0;
	if (output.size() > 0) {
		do {
			pos--;
			if (*pos == ' ' || *pos == '\\')
				ct++;
		} while (pos != output.begin() && ct < 2);

		if (pos == output.begin()) {
			output = "";
		} 
		else {
			output = std::string(output.begin(), pos + 1);
		}
	}
}

void eraseMToE(std::string& word)
{
	if (word.empty()){
		if (input.empty()) { // this also works same for output
			return;
		}
		else {
			// erase one character from input
			if (input.back() == ' ')
				input = std::string(input.begin(), input.end() - 1);

			if (output.size() != 1)
				output = std::string(output.begin(), output.end() - 1);
			else
				output = "";

			auto p = input.end() - 1;
			while (p != input.begin() && !isspace(*p)) {
				--p;
			}

			if (p == input.begin())  {
				word = input;
				input = "";
			}
			else  {
				word = std::string (p + 1, input.end());
				input = std::string(input.begin(), p);
			}
		}
	}
	else {
		word = std::string(word.begin(), word.end() - 1);
	}
}

void morseToEnglish(char t)
{
	std::cout << "morseToEnglish\n";

	char c = t;
	std::string word = "";
	do {
		if (c == ' ') {
			auto pos = code2.find(word);
			if (pos != code2.end()) {
				MakeRes(word, pos->second);
			}
			word = "";
		}
		else if (c == 127) {
			eraseMToE(word);			
		} 
		else {
			word += c;
		}
			std::string temp(input);
			temp += ' ';
			temp += word;
			printRes(temp, output);
			auto s = code2[word];
			std::cout << s;
	} while ((c = _getch()));
}

void englishToMorse(char t)
{
	std::cout << "englishToMorse\n";

	char c = t;
	do {
		auto pos = code1.find(c);
		if (pos != code1.end()) {
			MakeRes(c, pos->second);
		}
		if (c == 127) {
			eraseEnglishToMorse();
			printRes(input, output);
		}
	} while ((c = _getch()));
}

void Start()
{
	char c;
	c = _getch();

	if (c == '.' || c == '-')
		morseToEnglish(c);
	else if (c == 127) 
		return;
	else
		englishToMorse(c);
}

int main()
{
	printMsg();
	Start();
}
