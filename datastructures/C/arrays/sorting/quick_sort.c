#include<stdio.h>

void swap(int *p, int *q)
{
	int t;
	t=*q;
	*q=*p;
	*p=t;
}

int partition(int A[], int p, int r)
{
	int x,i,j;
	x=A[r];
	i=p-1;

	for(j=p;j<r;j++)
	{
		if (A[j]<=x) {
			i = i+1;
			swap(&A[i],&A[j]);
		}
	}
	swap(&A[i+1],&A[r]);

	return i+1;
}

void quick_sort(int A[], int p, int r)
{
	int q;

	if (p<r) {
		q=partition(A,p,r);
		quick_sort(A,p,q-1);
		quick_sort(A,q+1,r);
	} 
}

int main()
{
	int i;
	int A[] = {10,5,3,5,2,1};
	quick_sort(A,0,5);

	for(i=0;i<=5;i++) printf(" %d ",A[i]);

	return 0;
}