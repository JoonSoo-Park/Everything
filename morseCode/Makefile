GCC = g++
OBJS = main.o src.o
FLAGS = -Wall -g
TARGET = translator

all: $(TARGET)

$(TARGET) : $(OBJS)
	$(GCC) $(FLAGS) -o $@ $(OBJS)

main.o: src.h
	$(GCC) $(FLAGS) -c $*.cpp

clean:
	rm $(TARGET) $(OBJS)
