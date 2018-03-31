#file: makefile

a.out: Matritza.o PigLatin.o ex4.o
	gcc Matritza.o PigLatin.o ex4.o

ex4.o: ex4.c Matritza.h PigLatin.h
	gcc -c ex4.c

Matritza.o: Matritza.c Matritza.h
	gcc -c Matritza.c

PigLatin.o: PigLatin.c PigLatin.h
	gcc -c PigLatin.c
