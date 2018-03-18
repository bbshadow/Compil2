CC = gcc
FLEX = ./flex

LIBS = -lm 
CCFLAGS = -Wall -ggdb

OBJ = analyseur_lexical_flex.o util.o premiers.o suivants.o 

all: analyseur_syntaxique

analyseur_syntaxique: analyseur_syntaxique.c $(OBJ)
	$(CC) $(CCFLAGS) -o analyseur_syntaxique analyseur_syntaxique.c analyseur_syntaxique.h $(OBJ)

analyseur_lexical_flex.c: analyseur_lexical.flex
	$(FLEX) -o $@ $^

analyseur_lexical_flex.o: analyseur_lexical_flex.c
	$(CC) -c $(CCFLAGS) $^

util.o: util.c
	$(CC) -c $(CCFLAGS) $^

premiers.o: premiers.c
	$(CC) -c $(CCFLAGS) $^

suivants.o: suivants.c
	$(CC) -c $(CCFLAGS) $^



.PHONY : clean

clean:
	- rm -f $(OBJ)
	- rm -f analyseur_syntaxique
	- rm -f analyseur_lexical_flex.c
