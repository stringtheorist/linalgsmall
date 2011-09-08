#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"
#include "arithmetic.h"


int main() {
	matrix *mat;
	matrix *mat2;

	int rows, cols;

	rows = 10;
	cols = 5;

	mat = gen_rand_matrix(rows, cols);

	save_matrix(mat, "test_matrix.matrix");

	mat2 = load_matrix("test_matrix.matrix");

	if(matrix_equals(mat,mat2) == 0) {
		printf("IO Test successful!\n");
	} else {
		printf("IO Test failure \n");
	}
	display_matrix(mat);
	printf("\n \n");
	display_matrix(mat2);

	destroy_matrix(mat);
	destroy_matrix(mat2);

	return 0;
}

