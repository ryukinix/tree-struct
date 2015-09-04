GCC = gcc
LFLAGS = -Wall -o
TARGET =  binary-tree
DEBUG = -debug

all: 
	$(GCC) $(LFLAGS) $(TARGET).out $(TARGET).c
debug:
	$(GCC) $(DEBUG) $(LFLAGS) $(TARGET).out $(TARGET).c
clean: 
	rm -v *.out
run:
	./$(TARGET).out
