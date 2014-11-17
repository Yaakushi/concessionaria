CC = gcc -g

%.o: %.c
	$(CC) -c $<

all: teste

teste: lista.o sort.o test.o
	$(CC) $^ -o teste
