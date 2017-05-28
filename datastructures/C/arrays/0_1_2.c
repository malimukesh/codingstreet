#include<stdio.h>

void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}


int main()
{
	int A[] = {0,1,0,2,1,2};
	int loc_0=0;
	int loc_1=0;
	int loc_2=5;

	int i = 0;

	while (loc_1<=loc_2)
	{
		if (A[loc_1]==0) {
			swap(&A[loc_0],&A[loc_1]);
			loc_0++;
			loc_1++; 
		} else if (A[loc_1]==1) {
			loc_1++;
		} else if (A[loc_1]==2) {
			swap(&A[loc_1],&A[loc_2]);
			loc_2--;
		}
	}
	
	for(i=0;i<=5;i++) {
		printf(" %d ",A[i]);
	}
return 0;
}