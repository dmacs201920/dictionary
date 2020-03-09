
a.out:	dictionary.o	func.o	
	gcc -g dictionary.o func.o 

dictionary.o:	dictionary.c	headers.h
	gcc -g -c  dictionary.c

func.o:		func.c	headers.h
	gcc -g -c func.c

