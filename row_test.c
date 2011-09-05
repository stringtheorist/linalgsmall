#include <stdio.h>
#include "matrix.h"
#include "arithmetic.h"


int main() {
	
	int dim_x, dim_y;
	matrix *mat;
	matrix *row;
	
	dim_x = 10;
	dim_y = 5;


	mat = gen_rand_matrix(10,5);
	row = extract_row(mat, 5); 

	printf("mat \n");
	display_matrix(mat);

	printf("row 5\n");
	display_matrix(row);

	return 0;
}

	
