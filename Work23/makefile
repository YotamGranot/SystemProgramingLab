numbers: numbers.h convert.o numbers.o 
	gcc -g -Wall -pedantic -ansi -std=c90 numbers.o convert.o -o numbers 
numbers.o: numbers.c numbers.h
	gcc -c -Wall -pedantic -ansi -std=c90 numbers.c -o numbers.o
convert.o:convert.c numbers.h
	gcc -c -Wall -pedantic -ansi -std=c90 convert.c -o convert.o  
