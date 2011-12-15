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

sparse_matrix_csc *create_uninitialized_sparse_csc(int rows, int cols, int non_zeros) 
{
	
	sparse_matrix_csc *mat;
	mat = (sparse_matrix_csc *)calloc(sizeof(sparse_matrix_csc));
	mat->M = (double *)calloc(non_zeros*sizeof(double));
	mat->col_dim = cols;
	mat->row_dim = rows;
	mat->row_ptr = (int *)calloc(rows*sizeof(int));
	mat->col_ind = (int *)calloc(non_zeros*sizeof(int));
	mat->non_zeros = non_zeros;
	mat->uninit = non_zeros;
	return mat;
}


	
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

double *get_element(int pos_x, int pos_y, matrix *mat)
{
	
	if(pos_x < mat->row_dim && pos_x >= 0 && pos_y < mat->col_dim && pos_y >= 0) {
	
		return &((mat->M)[(mat->row_dim*pos_y) + pos_x]);
	} else {
		return NULL;
	}

}

int set_element(int pos_x, int pos_y, double value, matrix *mat)
{

	
	if(pos_x < mat->row_dim && pos_x >= 0 && pos_y < mat->col_dim && pos_y >= 0) {
		(mat->M)[(mat->row_dim*pos_y) + pos_x] = value;
		return 0;
	} else {
		return -1;
	}
}

int get_x_dimension(matrix *mat) 
{

	return mat->row_dim;
}

int get_y_dimension(matrix *mat)
{
	
	return mat->col_dim;
}


int display_matrix(matrix *mat)
{

	int i,j;

	if(mat == NULL) {
		fprintf(stderr, "Error: NULL matrix pointer encountered in function display_matrix. \n");
		return -1;
	}
	for(i = 0; i<mat->row_dim; i++) {
	
		//printf("%d |",i);
		for(j = 0; j<mat->col_dim; j++) {
		
			printf(" %10.7lf ", *get_element(i,j,mat));
		}
		printf(";\n");
	}
	return 0;

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


	for(i = 0; i<cols; i++) {
		(row->M)[i] = (mat->M)[index + (rows*i)];
	}

	return row;
}

int save_matrix(matrix *mat, char *filename) 
{
 	int rows, cols;
	int i, j;
	FILE *output_file;

	rows = mat->row_dim;
	cols = mat->col_dim;


		

	if(mat == NULL) {
		fprintf(stderr, "Error: NULL matrix pointer encountered in function save_matrix. \n");
		return -1;
	}
	
	
	output_file = fopen(filename, "w");
	fprintf(output_file, "%d : %d::",rows, cols);

	for(i = 0; i<rows; i++) {
	
		for(j = 0; j<cols; j++) {
		
			fprintf(output_file, "%lf,", *get_element(i,j,mat));
		}
		fprintf(output_file, ";\n");
	}

	fclose(output_file);
	return 0;

}	

matrix *load_matrix(char *filename) {
	
	FILE *input_file;
	int i, j;
	int rows, cols;
	matrix *mat;

	input_file = fopen(filename, "r");
	if(input_file == NULL) {
		fprintf(stderr, "ERROR: file %s does not exist! \n", filename);
		return NULL;
	}

	fscanf(input_file, "%d : %d ::", &rows, &cols); 

	mat = create_zero_matrix(rows, cols);

	for (i = 0; i < rows; i++) {
		for(j = 0; j< cols; j++) {
		fscanf(input_file, "%lf,", get_element(i, j, mat));
		}
		fscanf(input_file, ";\n");
	}

	fclose(input_file);
	return mat;
}



	
	
