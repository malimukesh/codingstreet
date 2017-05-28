#include<stdio.h>
void print_sub_sequences(int A[], int size)
{
	int i,j,k;
	
	for (i= 0 ; i<size; i++) {
		for(j=i; j<size; j++) {
			for(k=i;k<=j;k++) printf(" %d ",A[k]);
			printf("\n");
		}
	}

}

int main()
{
	int A[] = {1,2,3,4};

	print_sub_sequences(A,4);
	
	return 0;
}
