CC = gcc -g

%.o: %.c
	$(CC) -c $<

all: teste

teste: lista.o sort.o leitor.o concessionaria.o
	$(CC) $^ -o concessionaria

clean:
	rm -rf *.swp *~

distclean: clean
	rm -rf *.o teste core
