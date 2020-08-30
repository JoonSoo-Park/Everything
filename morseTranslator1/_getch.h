#ifndef _GETCH_H
#define _GETCH_H

#include <termios.h>
#include <unistd.h>
#include <string>

class BufferToggle
{
	struct termios t;

public:
	void off()
	{
		tcgetattr(STDIN_FILENO, &t);
		t.c_lflag &= ~ICANON;
		tcsetattr(STDIN_FILENO, TCSANOW, &t);
	}

	void on()
	{
		tcgetattr(STDIN_FILENO, &t);
		t.c_lflag |= ICANON;
		tcsetattr(STDIN_FILENO, TCSANOW, &t);
	}
};

char _getch()
{
	char c;
	struct termios ter;

	tcgetattr(STDIN_FILENO, &ter);
	ter.c_lflag &= ~ICANON;
	ter.c_lflag &= ~ECHO;
	ter.c_cc[VMIN] = 1;
	ter.c_cc[VTIME] = 0;
	tcsetattr(STDIN_FILENO, TCSANOW, &ter);

	c = getchar();

	tcgetattr(STDIN_FILENO, &ter);
	ter.c_lflag |= ICANON;
	ter.c_lflag |= ECHO;
	tcsetattr(STDIN_FILENO, TCSANOW, &ter);

	return c;
}

#endif
