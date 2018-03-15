CC=clang
CFLAGS=-std=c99 -Wall -Wextra -g
LDFLAGS=-lm
EXEC=annuaire
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)

all: $(EXEC) clean

annuaire: $(OBJ)
		$(CC) -o $@ $^ $(LDFLAGS)

annuaire.o: hachage.h

%.o: %.c
		$(CC) -o $@ -c $< $(CFLAGS)

clean:
		rm -rf *.o

mrproper: clean
		rm -rf $(EXEC)