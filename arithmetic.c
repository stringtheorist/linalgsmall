#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"
#include "arithmetic.h"



matrix *add_matrices(matrix *mat1, matrix *mat2)
{
	matrix *mat3;
	int dim_x,dim_y;
	int i,j;


	if ((mat1->dimension_x != mat2->dimension_x) || (mat1->dimension_y!=mat2->dimension_y ) ) {
		return NULL;
	}

	dim_x = mat1->dimension_x;
	dim_y = mat2->dimension_y;

	mat3 = create_zero_matrix(dim_x,dim_y);

	for(j = 0;j<dim_y;j++) {
		for(i = 0; i<dim_x; i++) {
			(mat3->M)[i+(dim_x*j)] = (mat2->M)[i+(dim_x*j)] + (mat1->M)[i+(dim_x*j)];
		}
	}

	return mat3;
}

matrix *negate_matrix(matrix *mat)
{
	int i;
	int dim_x, dim_y;
	dim_x = mat->dimension_x;
	dim_y = mat->dimension_y;

	for(i = 0; i < (dim_x*dim_y); i++) {
		(mat->M)[i] = -(mat->M)[i];
	}
	
	return mat;
}

matrix *multiply_matrices(matrix *mat1, matrix *mat2)
{
 	matrix *mat3;
	int dim_x1, dim_y1, dim_x2, dim_y2;
	int i, j, k;
	double dot_i_j;
	
	dim_x1 = mat1->dimension_x;
	dim_y1 = mat1->dimension_y;
	dim_x2 = mat2->dimension_x;
	dim_y2 = mat2->dimension_y;
	
	if(dim_y1 != dim_x2) {
		return NULL;
	}

	mat3 =(matrix *)malloc(sizeof(matrix));
	mat3->dimension_x = dim_x1;
	mat3->dimension_y = dim_y2;

	mat3->M = (double *)malloc(dim_x1*dim_y2*sizeof(double));
	
	
	for(j = 0; j<dim_y2; j++) {
		for(i = 0; i<dim_x1; i++) {
			dot_i_j = 0;
			for(k = 0; k<dim_x2; k++) {
				dot_i_j += ((mat1->M)[i+(dim_x1*k)])*((mat2->M)[k+(dim_x2*j)]);
			}
			(mat3->M)[i+(dim_x2*j)] = dot_i_j;
		}
	}


	return mat3;
}
