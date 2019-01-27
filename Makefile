# -*- Makefile -*-

main: main.o grafo.o
	gcc main.o grafo.o -o tp0

main.o: main.c 
	gcc -c main.c

grafo.o: grafo.c
	gcc -c grafo.c

