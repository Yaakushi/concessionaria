OUTPUTFILE=../bin/concessionaria
CC = gcc -g -Wall

%.o: %.c
	$(CC) -c $<

all: $(OUTPUTFILE)

$(OUTPUTFILE): lista.o sort.o leitor.o concessionaria.o
	mkdir -p ../bin
	$(CC) $^ -o $(OUTPUTFILE)

clean:
	rm -rf *.swp *~ *.bak core

distclean: clean
	rm -rf *.o $(OUTPUTFILE)
