matrix_test: matrix.o
	gcc matrix.o -omatrix_test

matrix.o: matrix.c matrix.h
	gcc -c matrix.c
