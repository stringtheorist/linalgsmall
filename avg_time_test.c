#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matrix.h"
#include "arithmetic.h"


double avg_time(int dim, int iterations);



int main(int argc, char *argv[]) 
{
	int dim, dim_upper, dim_lower;
	double time_elapsed;
	FILE *ofp;

	dim_lower = atoi(argv[1]);
	dim_upper = atoi(argv[2]);


	ofp = fopen("times", "w");
	
	for( dim = dim_lower; dim<dim_upper; dim++) {

		time_elapsed = avg_time(dim,25);

		printf("dimension = %d, time = %lfms \n", dim, time_elapsed);

		fprintf(ofp, "%d, %lf; \n ", dim, time_elapsed);
		time_elapsed = 0.0;
	}
	
	fclose(ofp);
	return 0;
}


double avg_time(int dim, int iterations)
{
	double t1;
	double t2;
	int i;
	double time_elapsed, avg_time;
	matrix *mat1, *mat2, *mat3;

	t1 = (double)clock()/CLOCKS_PER_SEC;

	mat3 = create_zero_matrix(dim,dim);
	
	mat1 = gen_rand_matrix(dim, dim);
	mat2 = gen_rand_matrix(dim, dim);
	
	for(i = 0; i< iterations; i++) {

		multiply_matrices(mat1, mat2, mat3);
	}

	t2 = (double)clock()/CLOCKS_PER_SEC;
	time_elapsed = t2 - t1;

	time_elapsed = time_elapsed*1000;
	
	avg_time = time_elapsed/iterations;

	destroy_matrix(mat1);
	destroy_matrix(mat2);
	destroy_matrix(mat3);
	
	return avg_time;

}




		
		
		
		