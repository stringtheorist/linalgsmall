
#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"
#include "arithmetic.h"



matrix *add_matrices(matrix *mat1, matrix *mat2)
{
	matrix *mat3;
	int rows,cols;
	int i,j;


	if ((mat1->row_dim != mat2->row_dim) || (mat1->col_dim!=mat2->col_dim ) ) {
		return NULL;
	}

	rows = mat1->row_dim;
	cols = mat2->col_dim;

	mat3 = create_zero_matrix(rows,cols);

	for(j = 0;j<cols;j++) {
		for(i = 0; i<rows; i++) {
			(mat3->M)[i+(rows*j)] = (mat2->M)[i+(rows*j)] + (mat1->M)[i+(rows*j)];
		}
	}

	return mat3;
}

matrix *negate_matrix(matrix *mat)
{
	int i;
	int rows, cols;
	rows = mat->row_dim;
	cols = mat->col_dim;

	for(i = 0; i < (rows*cols); i++) {
		(mat->M)[i] = -(mat->M)[i];
	}
	
	return mat;
}

matrix *multiply_matrices(matrix *mat1, matrix *mat2)
{
 	matrix *mat3;
	int rows1, cols1, rows2, cols2;
	int i, j, k;
	double dot_i_j;
	
	rows1 = mat1->row_dim;
	cols1 = mat1->col_dim;
	rows2 = mat2->row_dim;
	cols2 = mat2->col_dim;
	
	if(cols1 != rows2) {
		return NULL;
	}

	mat3 = create_zero_matrix(rows1, cols2);

	for(j = 0; j<cols2; j++) {
		for(i = 0; i<rows1; i++) {
			dot_i_j = 0;
			for(k = 0; k<rows2; k++) {
				dot_i_j += ((mat1->M)[i+(rows1*k)])*((mat2->M)[k+(rows2*j)]);
			}
			(mat3->M)[i+(rows1*j)] = dot_i_j;
		}
	}


	return mat3;
}
