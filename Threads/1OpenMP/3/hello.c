#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

#define NROWS 5
#define NCOLS 3

int soma(int mat[][NCOLS], int id)
{
	int i;
	int s = 0;
	for(i=0;i<NCOLS;++i)
	{
		s += mat[id][i];
	}
	return s;
}

int obtemMaiorNumero(int mat[][NCOLS], int id)
{
	int maiorPos = 0;
	int i;
	for(i=1;i<NCOLS;++i)
	{	
		if (mat[id][i] > mat[id][maiorPos])
			maiorPos = i;
	}
	return mat[id][maiorPos];
}

int main (int argc, char *argv[]) 
{
	int nthreads, tid;

	int mat[NROWS][NCOLS] = {{1,2,3},{4,5,6},{7,8,9},{10,11,12},{13,14,15}};

	omp_set_num_threads(NROWS+1);
	//se não usar, fica 1 thread por cada cpu

	// Fork a team of threads giving them their own copies of variables
	
	#pragma omp parallel private(nthreads, tid)
	{
	  	tid = omp_get_thread_num();              	// Obtain thread number
  		printf("Hello World from thread = %d\n", tid);

	 	if (tid == 0) // Only master thread does this
	 	{
			nthreads = omp_get_num_threads();
			printf("Number of threads = %d\n", nthreads);
	  	}
	  	else
	  	{
	  		//int ret = soma(mat, tid-1);
	  		//printf("Soma na thread %d: %d\n", tid, ret);
	  		
	  		int ret = obtemMaiorNumero(mat, tid-1);
	  		printf("O maior numero na thread %d: %d\n", tid, ret);
	  	}
	  	
	} // All threads join master thread and disband
	
	return(0);
}

