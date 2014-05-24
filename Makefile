CC = gcc
CFLAGS = -ansi -Wall -Wextra -pedantic -O2

all: cadeias.o tarefa2.o
		$(CC) $(CFLAGS) -o all  cadeias.c tarefa2.c

testcadeias: main.o cadeias.o
		$(CC) $(CFLAGS) -o maincadeias main.c cadeias.c

clean:
		rm -f *.o