GCC = g++
CFLAG = -Wall -g
OBJS = main.o DerivedE2M.o DerivedM2E.o
TARGET = translator

all: $(TARGET)

$(TARGET): $(OBJS)
	$(GCC) $(CFLAG) -o $@ $(OBJS)

main.o: Base.h DerivedE2M.h DerivedM2E.h _getch.h
	$(GCC) $(CFLAG) -c $*.cpp

DerivedE2M.o: Code.h
	$(GCC) $(CFLAG) -c $*.cpp

DerivedM2E.o: Code.h
	$(GCC) $(CFLAG) -c $*.cpp

clean:
	rm $(TARGET) $(OBJS)
