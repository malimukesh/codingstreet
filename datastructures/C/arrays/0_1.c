#include<stdio.h>

void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

int main()
{
	int A[] = {0,1,0,1,0,0,0,1};
	int n = 7;
	int high = 7;
	int i;
	for(i=0;i<high;i++) {
		if (A[i]==1) {
			swap(&A[i],&A[high]);
			high--;
			i--;
		}
	}

	for(i=0;i<=n;i++) {
		printf(" %d ",A[i]);
	}
	
	return 0;
}