//Col Major order storage and indexing functions for matrices. 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matrix.h"


/*
int main() 
{

	matrix *test_mat1;
	int rows, cols;



	printf("Testing \n");
	rows = cols = 4;
	test_mat1 = create_zero_matrix(rows, cols);
	display_matrix(test_mat1);
	destroy_matrix(test_mat1);

	return 0;
}
*/

matrix *create_zero_matrix(int rows, int cols) 
{

	matrix *mat;
	int i,len;

	len = rows*cols;
	mat = (matrix *)malloc(sizeof(matrix));
	mat->M = (double *)malloc((len)*sizeof(double));
	mat->row_dim = rows;
	mat->col_dim = cols;

	
	for(i = 0; i<len ; i++){ 
	
		(mat->M)[i] = 0.0;
	}

	return mat;
}


void destroy_matrix(matrix *mat)
{
	free(mat->M);
	free(mat);

}

double get_element(int pos_x, int pos_y, matrix *mat)
{
	return ((mat->M)[(mat->row_dim*pos_y) + pos_x]);

}

int set_element(int pos_x, int pos_y, double value, matrix *mat)
{

	(mat->M)[(mat->row_dim*pos_y) + pos_x] = value;
	return 0;
}

int get_x_dimension(matrix *mat) 
{

	return mat->row_dim;
}

int get_y_dimension(matrix *mat)
{
	
	return mat->col_dim;
}


void display_matrix(matrix *mat)
{

	int i,j;

	for(i = 0; i<mat->row_dim; i++) {
	
		//printf("%d |",i);
		for(j = 0; j<mat->col_dim; j++) {
		
			printf(" %10.7lf ", get_element(i,j,mat));
		}
		printf(";\n");
	}

}

matrix *gen_rand_matrix(int rows, int cols) 
{
	
	matrix *mat;
	int i,len;

	len = rows*cols;
	mat = create_zero_matrix(rows, cols);
	
	for(i = 0; i<len; i++) {
		(mat->M)[i] = (((double)rand()*2)/RAND_MAX) - 1;
	}
	
	return mat;
}



matrix *extract_row(matrix *mat, int index)
{
	
	matrix *row;
	int i;
	int rows, cols;

	

	cols = mat->col_dim;
	rows = mat->row_dim;

	if(index >=rows) {
	 	return NULL;
	}

	
	row = create_zero_matrix(1,cols);

	printf("%d  %d \n",rows, cols);

	for(i = 0; i<cols; i++) {
		printf("%d \n", i);
		printf("%lf \n", (mat->M)[index + (rows*i)]);
		(row->M)[i] = (mat->M)[index + (rows*i)];
	}

	return row;
}

