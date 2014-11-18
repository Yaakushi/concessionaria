CC = gcc -g

%.o: %.c
	$(CC) -c $<

all: teste

teste: lista.o sort.o test.o
	$(CC) $^ -o teste

clean:
	rm -rf *.swp *~

distclean:
	rm -rf *.o teste core
