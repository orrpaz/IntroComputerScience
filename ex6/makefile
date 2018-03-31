#file: makefile

a.out: GADT.o main.o
	gcc GADT.o main.o

main.o: main.c GADT.h 
	gcc -c main.c

GADT.o: GADT.c GADT.h
	gcc -c GADT.c

