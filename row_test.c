#include <stdio.h>
#include "matrix.h"
#include "arithmetic.h"
#include <time.h>

int main() {
	
	int dim_x, dim_y;
	matrix *mat;
	matrix *row;
	
	dim_x = 10;
	dim_y = 5;



	srand(time(NULL));
	mat = gen_rand_matrix(10,5);
	row = extract_row(mat, 5); 

	printf("mat \n");
	display_matrix(mat);

	printf("row 5\n");
	display_matrix(row);

	destroy_matrix(row);
	destroy_matrix(mat);
	return 0;
}

	
