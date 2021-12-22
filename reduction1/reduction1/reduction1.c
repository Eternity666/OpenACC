#include<stdio.h>
#define N 101

int main()
{
	int a[N], i, ired;
	for (i = 0; i < N; i++)
	{
		a[i] = i;
	}
	ired = 0;
#pragma acc parallel
	{
#pragma acc loop reduction(+:ired)
		for (i = 0; i < N; i++)
		{
			ired += a[i];
		}
	}
	printf("ired = %d\n", ired);
	return 0;
}