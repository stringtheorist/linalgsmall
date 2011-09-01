//Col Major order storage and indexing functions for matrices. 

#include <stdio.h>
#include <stdlib.h>



typedef struct matrix
{
	double *M;
	int dimension_x;
	int dimension_y;
}matrix;

matrix *create_zero_matrix(int dim_x, int dim_y);
void destroy_matrix(matrix *mat);
double get_element(int pos_x, int pos_y,matrix *mat);
int set_element(int pos_x, int pos_y,double value, matrix *mat);
int get_x_dimension(matrix *mat);
int get_y_dimension(matrix *mat);
void display_matrix(matrix *mat);


int main() 
{

	matrix *test_mat1;
	int dim_x, dim_y;



	printf("Testing \n");
	dim_x = dim_y = 4;
	test_mat1 = create_zero_matrix(dim_x, dim_y);
	display_matrix(test_mat1);
	destroy_matrix(test_mat1);

	return 0;
}


matrix *create_zero_matrix(int dim_x, int dim_y) 
{

	matrix *mat;
	int i,len;

	len = dim_x*dim_y;
	mat = (matrix *)malloc(sizeof(matrix));
	mat->M = (double *)malloc((len)*sizeof(double));
	mat->dimension_x = dim_x;
	mat->dimension_y = dim_y;

	
	for(i = 0; i<len ; i++) 
	{
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
	return ((mat->M)[(mat->dimension_y*pos_y) + pos_x]);

}

int set_element(int pos_x, int pos_y, double value, matrix *mat)
{

	(mat->M)[(mat->dimension_y*pos_y) + pos_x] = value;
	return 0;
}

int get_x_dimension(matrix *mat) 
{

	return mat->dimension_x;
}

int get_y_dimension(matrix *mat)
{
	
	return mat->dimension_y;
}


void display_matrix(matrix *mat)
{

	int i,j;

	for(i = 0; i<mat->dimension_x; i++)
	{
		printf("%d |",i);
		for(j = 0; j<mat->dimension_y; j++)
		{
			printf(" %f ", get_element(i,j,mat));
		}
		printf("|\n");
	}

}


