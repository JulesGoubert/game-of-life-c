.PHONY: all clean mrproper

sources := $(wildcard %.c)
objects := $(patsubst %.c, %.o, $(sources))
executables := gameOfLife

CC := gcc
CFLAGS := -Wall -O

all: $(executables)

%: %.o
	$(CC) $(CFLAGS) -o $@ $<

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -vf $(objects)

mrproper: clean
	rm -vf $(executables)
