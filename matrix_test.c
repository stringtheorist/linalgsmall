#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "matrix.h"
#include "arithmetic.h"


int main() 
{

	matrix *mat1;
	matrix *mat2;
	matrix *mat3;

	mat1 = gen_rand_matrix(4,3);
	mat2 = gen_rand_matrix(3,5);

	mat3 = multiply_matrices(mat1, mat2);
	

	printf("mat1:\n");
	display_matrix(mat1);
	printf("mat2:\n");
	display_matrix(mat2);
	printf("mat3 = mat1*mat2:\n");
	display_matrix(mat3);
	
	destroy_matrix(mat1);
	destroy_matrix(mat2);
	destroy_matrix(mat3);
	return 0;
}



	

	
