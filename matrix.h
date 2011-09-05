#ifndef __MATRIX__H__
#define __MATRIX__H__
typedef struct matrix
{
	double *M;
	int row_dim;
	int col_dim;
}matrix;

matrix *create_zero_matrix(int rows, int cols);
void destroy_matrix(matrix *mat);
double get_element(int pos_x, int pos_y,matrix *mat);
int set_element(int pos_x, int pos_y,double value, matrix *mat);
int get_x_dimension(matrix *mat);
int get_y_dimension(matrix *mat);
void display_matrix(matrix *mat);
matrix *gen_rand_matrix(int rows, int cols);
matrix *extract_row(matrix *mat, int index);
#endif
