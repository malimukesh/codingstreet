#include<stdio.h>
int max_sub_array_sum(int A[], int size)
{
	int final_max = -50000000;
	int current_max= 0;
	int i;	
	int start = 0;
	int end = 0;
	int s;
	for (i=0; i<size; i++)
	{
		current_max+=A[i];
		if (current_max>final_max) {
			final_max = current_max;	
			start = s;
			end=i;
		}
		if(current_max<0) {
			s=i+1;
			current_max=0;
		}	
	}
	printf("\n [S=%d, E=%d ] \n",start, end);
	return final_max;
}

int main()
{
	int A[] = {-1,1,-2,0,1,3,-2,2,3};
	int i ,n=9 ; 
	for(i=0; i<n; i++) printf(" %d ",A[i]);	
	printf("\n %d ", max_sub_array_sum(A,n));
}

