CC = gcc
CFLAGS = -ansi -Wall -Wextra -pedantic -g

all: etapa2

etapa2: etapa2.o cadeias.o hash_table.o main.o
	$(CC) $(CFLAGS) -o etapa2 etapa2.o cadeias.o hash_table.o main.o

clean:
	rm -f *.o
