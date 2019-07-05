# Compiler
CC = g++
CFLAGS = -std=c++11

# Objects to create
OBJ = item.o list.o

# Pattern rule to create object files
%.o: %.cpp %.h
	$(CC) -c -o $@ $< $(CFLAGS)

# Make everything
.PHONY: all
all: tasker

# Ultimate target
tasker: main.cpp $(OBJ)
	$(CC) -o $@ $< $(OBJ) $(CFLAGS)

# Dependencies
list.o: item.o

# Clean up rule
.PHONY: clean
clean:
	rm *.o
