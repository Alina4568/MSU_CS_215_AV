#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int m1, n1, m2, n2, i, j, k;
	double f;
	double max = 1000, min = -1000;
	scanf("%d %d %d %d", &m1, &n1, &m2, &n2);
	double **A, **B, **C;
	A = malloc(m1 * sizeof(double*));
	B = malloc(m2 * sizeof(double*));
	C = malloc(n2 * sizeof(double*));
	
	for(i = 0; i < m1; i++)
		A[i] = malloc(n1 * sizeof(double*));
	for(i = 0; i < m2; i++)
		B[i] = malloc(n2 * sizeof(double*));
	for(i = 0; i < m1; i++)
		C[i] = malloc(m1 * sizeof(double*));
	
	if(n1 == m2) {
	    printf("  A \n");
		for(i = 0; i < m1; i++){
			for(j = 0; j < n1; j++){
			    	A[i][j] = (double) rand() / RAND_MAX * (max - min) + min;
			    	printf("%lf  ", A[i][j]);
			}
			printf("\n");
		}
		
		printf("\n");
			
		printf("  B \n");
		for(i = 0; i < m2; i++){
			for(j = 0; j < n2; j++){
			    	B[i][j] = (double) rand() / RAND_MAX * (max - min) + min;
			    	printf("%lf  ", B[i][j]);
			}
			printf("\n");
		}
		
		printf("\n");
			
		for(i = 0; i < m1; i++)
			for(j = 0; j < n2; j++) {
				C[i][j] = 0;
				for(k = 0; k < m2; k++)
					C[i][j] += A[i][k] * B[k][j];
			}
			
		printf("  A*B \n");
		for(i = 0; i < m1; i++){
			for(j = 0; j < n2; j++)
				printf("%lf  ", C[i][j]); 
			printf("\n");
		}
	}

	return 0;
}