#ifndef __MATRIX__H__
#define __MATRIX__H__
typedef struct matrix
{
	double *M;
	int row_dim;
	int col_dim;
}matrix;

typedef struct sparse_matrix_csc
{
	double *M;
	int row_dim;
	int col_dim;
	int *col_ind;
	int *row_ptr;
	int non_zeros;
	int uninit;
}sparse_matrix_csc;

int set_row_sparse(int row_index, int *col_inds, int non_zeros, double *row);
sparse_matrix_csc *create_uninitialized_sparse_csc(int rows, int cols, int non_zeros);
matrix *create_zero_matrix(int rows, int cols);
void destroy_matrix(matrix *mat);
double *get_element(int pos_x, int pos_y,matrix *mat);
int set_element(int pos_x, int pos_y,double value, matrix *mat);
int get_x_dimension(matrix *mat);
int get_y_dimension(matrix *mat);
int display_matrix(matrix *mat);
matrix *gen_rand_matrix(int rows, int cols);
matrix *extract_row(matrix *mat, int index);
matrix *load_matrix(char *filename);
int save_matrix(matrix* mat, char *filename);
#endif
