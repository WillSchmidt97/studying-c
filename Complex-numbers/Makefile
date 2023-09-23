CC = gcc
CFLAGS = -Wall -Wextra

all: complex_numbers

complex_numbers: complex_numbers.o main.o
	$(CC) $(CFLAGS) -o complex_numbers complex_numbers.o main.o

complex_numbers.o: complex_numbers.c complex_numbers.h
	$(CC) $(CFLAGS) -c complex_numbers.c

main.o: main.c complex_numbers.h
	$(CC) $(CFLAGS) -c main.c

clean:
	rm -f *.o complex_numbers