comp: complex.h complex.o analysis.o mycomp.o 
	gcc -g -Wall -pedantic -ansi -std=c90 complex.o mycomp.o analysis.o -o comp -lm


mycomp.o: complex.h mycomp.c
	gcc -c -Wall -pedantic -ansi -std=c90 mycomp.c -o mycomp.o -lm


analysis.o: complex.h analysis.c
	gcc -c -Wall -pedantic -ansi -std=c90 analysis.c -o analysis.o -lm


complex.o: complex.h complex.c
	gcc -c -Wall -pedantic -ansi -std=c90 complex.c -o complex.o -lm
