matrix_test: matrix_test.o
	gcc matrix_test.o matrix.o arithmetic.o -omatrix_test

matrix_test.o: matrix.o arithmetic.o matrix.h arithmetic.h
	gcc -c matrix_test.c

arithmetic.o: matrix.o matrix.h arithmetic.h
	gcc -c arithmetic.c

matrix.o: matrix.c matrix.h
	gcc -c matrix.c



