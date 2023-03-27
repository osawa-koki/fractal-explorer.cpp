CC=g++
CFLAGS=-Wall -Wextra -Wpedantic -std=c++17 -O3 -I./include
LDFLAGS=-lpng

SRCDIR=./src
OBJDIR=./bin
TARGET=$(OBJDIR)/main

SRC=$(wildcard $(SRCDIR)/*.cpp)
OBJ=$(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SRC))

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

$(TARGET): $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

.PHONY: clean
clean:
	rm -f $(OBJDIR)/*.o $(TARGET)

.PHONY: run
run: $(TARGET)
	$(TARGET)
