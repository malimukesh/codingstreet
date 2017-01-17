#include<stdio.h>

void print_array(int A[],int size)
{
	int i;
	for(i=0;i<size;i++)
		printf(" %d ",A[i]);
}

void merge(int A[], int start, int mid, int end)
{
	int n1,n2,i,j,k;
	n1 = mid-start+1;
	n2 = end-mid;

	int L[n1];
	int R[n2];

	i=j=k=0;

	for(i=0;i<n1;i++)
		L[i]=A[start+i];
	for(j=0;j<n2;j++)
		R[j]=A[mid+j+1];

	i=j=0;
	k=start;

	while(i<n1 && j<n2) 
	{
		if (L[i]<R[j]) {
			A[k]=L[i];
			i++;
		} else {
			A[k]=R[j];
			j++;
		}
		k++;
	}

	while(i<n1)
	{
		A[k]=L[i]; i++; k++;
	}

	while(j<n2)
	{
		A[k] = R[j]; j++; k++;
	}
}

void merge_sort(int A[],int start, int end)
{
	if(start<end) {
		int mid = (start+end)/2;
		merge_sort(A,start, mid);
		merge_sort(A,mid+1, end);
		merge(A,start,mid,end);
	}
}

int main()
{
	int A[] = {1199999911,2,3,10,4,5,8,7,6};
	int i=0;

	merge_sort(A,0,8);

	print_array(A,9);

	return 0;
}