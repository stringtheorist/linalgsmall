all: row_test matrix_test file_io_test matrix_benchmark_test

matrix_benchmark_test: matrix_benchmark_test.o
	gcc matrix_benchmark_test.o matrix.o arithmetic.o -oavg_time_test

file_io_test: file_io_test.o
	gcc file_io_test.o matrix.o arithmetic.o -ofile_io_test

row_test: row_test.o matrix.o arithmetic.o
	gcc row_test.o matrix.o arithmetic.o -orow_test

matrix_test: matrix_test.o arithmetic.o matrix.o
	gcc matrix_test.o matrix.o arithmetic.o -omatrix_test

matrix_benchmark_test.o: matrix_benchmark_test.c matrix.o arithmetic.o matrix.h arithmetic.h
	gcc -c matrix_benchmark_test.c

file_io_test.o: file_io_test.c matrix.o arithmetic.o matrix.h arithmetic.h
	gcc -c file_io_test.c


row_test.o: row_test.c matrix.o arithmetic.o matrix.h arithmetic.h
	gcc -c row_test.c

matrix_test.o: matrix_test.c matrix.o arithmetic.o matrix.h arithmetic.h
	gcc -c matrix_test.c

arithmetic.o: arithmetic.c matrix.o matrix.h arithmetic.h
	gcc -c arithmetic.c

matrix.o: matrix.c matrix.h
	gcc -c matrix.c



