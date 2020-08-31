#ifndef BASE_H
#define BASE_H

class Base {
public:
	virtual ~Base() {};
	virtual bool translate(const char) = 0;
	Base& operator=(const Base&) = delete;
private:
	virtual void erase() = 0;
};

#endif
