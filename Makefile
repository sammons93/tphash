CC=clang
CFLAGS=-Wall -Wextra -std=c99 -g
LDFLAGS=-lm
EXEC=hachage

all: $(EXEC)

hachage: hachage.o annuaire.o
	$(CC) -o hachage.o annuaire.o $(LDFLAGS)

hachage.o: hachage.c
	$(CC) -o hachage.o -c hachage.c $(CFLAGS)

annuaire.o: annuaire.c hachage.h
	$(CC) -o annuaire.o -c annuaire.c $(CFLAGS)

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)