#include<stdio.h>
#include<time.h>
#define M 128
#define N 256

int main()
{
	double start, finish;
	double total;
	start = clock();
	int i, j, a[M][N], b[M][N], c[M][N];
	for(i = 0; i<M; i++)
		for (j = 0; j < N; j++)
		{
			a[i][j] = -1;
			b[i][j] = c[i][j] = i + j;
		}

#pragma acc kernels
	for(i = 0; i<M; i++)
		for (j = 0; j < N; j++)
		{
			a[i][j] = b[i][j] + c[i][j];
		}
	printf("a[M-1][N-1] = %d\n", a[M - 1][N - 1]);
	finish = clock();
	total = (finish - start) / CLOCKS_PER_SEC;
	printf("%f\n", total);
	return 0;
}