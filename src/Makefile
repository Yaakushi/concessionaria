OUTPUTFILE=../bin/concessionaria
CC = gcc -g -Wall

%.o: %.c
	$(CC) -c $<

all: $(OUTPUTFILE)

$(OUTPUTFILE): lista.o sort.o leitor.o concessionaria.o
	$(CC) $^ -o $(OUTPUTFILE)

clean:
	rm -rf *.swp *~

distclean: clean
	rm -rf *.o teste core
