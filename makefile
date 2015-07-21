GCC = gcc
LFLAGS = -Wall -o

# the build target.
TARGET =  binary-tree

all: 
	$(GCC) $(LFLAGS) $(TARGET).out $(TARGET).c
clean: 
	rm *.out