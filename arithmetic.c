
#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"
#include "arithmetic.h"



int add_matrices(matrix *mat1, matrix *mat2, matrix *result)
{
	int rows,cols;
	int i,j;


	if ((mat1->row_dim != mat2->row_dim) || (mat1->col_dim!=mat2->col_dim ) ) {
		return -1;
	} else if((mat1->row_dim != result->row_dim) || (mat1->col_dim != result->col_dim)) {
		return -2;
	}

	rows = mat1->row_dim;
	cols = mat2->col_dim;

	for(j = 0;j<cols;j++) {
		for(i = 0; i<rows; i++) {
			(result->M)[i+(rows*j)] = (mat2->M)[i+(rows*j)] + (mat1->M)[i+(rows*j)];
		}
	}

	return 0;
}

int negate_matrix(matrix *mat)
{
	int i;
	int rows, cols;

	if (mat == NULL) {
		return -1;
	}

	rows = mat->row_dim;
	cols = mat->col_dim;

	for(i = 0; i < (rows*cols); i++) {
		(mat->M)[i] = -(mat->M)[i];
	}
	
	return 0;
}

int multiply_matrices(matrix *mat1, matrix *mat2, matrix *result)
{
	int rows1, cols1, rows2, cols2, rows_result, cols_result;
	int i, j, k;
	double dot_i_j;
	
	rows1 = mat1->row_dim;
	cols1 = mat1->col_dim;
	rows2 = mat2->row_dim;
	cols2 = mat2->col_dim;
	rows_result = result->row_dim;
	cols_result = result->col_dim;
	
	if(cols1 != rows2) {
		return -1;
	} else if((rows1 != rows_result)||(cols2 != cols_result)) {
		return -2;
	}


	for(j = 0; j<cols2; j++) {
		for(i = 0; i<rows1; i++) {
			dot_i_j = 0;
			for(k = 0; k<rows2; k++) {
				dot_i_j += ((mat1->M)[i+(rows1*k)])*((mat2->M)[k+(rows2*j)]);
			}
			(result->M)[i+(rows1*j)] = dot_i_j;
		}
	}


	return 0;
}

int matrix_equals(matrix *mat1, matrix *mat2) {
	
	int flag;
	int i, j;
	int rows, cols;
	
	if ((mat1->row_dim != mat2->row_dim) || (mat1->col_dim!=mat2->col_dim ) ) {
		return 2;
	}
	
	rows = mat1->row_dim;
	cols = mat2->col_dim;

	flag = 0;
	for(j = 0; j < cols; j++) {
		for(i = 0; i < rows; i++) {
			if((*get_element(i,j,mat1)) != (*get_element(i,j,mat2))) {
				flag = 1;
			} else {
				if(flag != 1) {
					flag = 0;
				}
			}

		}
	}

	return flag;
}
