# macro tells which compiler to use
CC = g++

# macro says using c++11 standard
CFLAGS = -std=c++11 -c

# run "make all" to run badsort
all: badsort

# make the bad sort program
bad: badsort.o
	$(CC) badsort.o -o bad

badsort.o:
	$(CC) $(CFLAGS) badsort.cpp


clean:
	rm *.o
	rm -f bad.out
	rm badsort