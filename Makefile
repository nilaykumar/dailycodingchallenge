CC = g++
CFLAGS = -Wall

SRCS = $(wildcard *.cpp)
OBJS = $(patsubst %.cpp,%.o,$(SRCS))

all: $(OBJS)

%.o: %.cpp
	$(CC) $(CFLAGS) -o $@ $<

.PHONY: clean

clean:
	rm -f *.o
