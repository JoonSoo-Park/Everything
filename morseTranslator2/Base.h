#ifndef BASE_H
#define BASE_H

class Base {
public:
	virtual ~Base() {};
	virtual bool translate(char) = 0;
	Base(const Base&) = delete;
	Base& operator=(const Base&) = delete;
};

#endif
