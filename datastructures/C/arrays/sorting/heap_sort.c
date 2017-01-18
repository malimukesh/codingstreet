#include<stdio.h>

void swap(int *p, int *q)
{
	int t;
	t=*p;
	*p=*q;
	*q=t;
}

void max_heapify(int A[],int pos, int size)
{
	int left;
	int right;
	int largest = pos;

	left = 2 * pos + 1;
	right = 2 * pos + 2;

	if (left < size && A[left]>A[largest]) {
		largest = left;
	}

	if (right < size && A[right] > A[largest]) {
		largest = right;
	}

	if(pos!=largest) {
		swap(&A[pos],&A[largest]);
		max_heapify(A,largest,size);
	}

}

void heap_sort(int A[], int size)
{
	int i;
	
	for (i=size/2;i>=0;i--) {
		max_heapify(A,i,size);
	}

	for(i=size;i>0;i--)
	{
		swap(&A[0],&A[size]);
		size--;
		max_heapify(A,0,size);
	}
}

int main()
{
	int i;
	int A[] = {50,51,49,48,47};
	heap_sort(A,4);
	
	for (i=0;i<=4;i++) printf(" %d ",A[i]);
	
	return 0;
}