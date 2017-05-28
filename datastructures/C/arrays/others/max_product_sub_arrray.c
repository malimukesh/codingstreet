#include<stdio.h>

int min(int a, int b)
{
	if (a<b) {
		return a;
	} else {
		return b;
	}
}

int max(int a, int b)
{
	if (a>b) {
		return a;
	} else {
		return b;
	}
}

int max_subarray_product(int A[], int size)
{
	int max_product = A[0];
	int tmp_min_product = A[0];
	int tmp_max_product = A[0];

	int i;
	
	for (i=0; i<size; i++)
	{
		if (A[i]==0) {
			tmp_max_product = A[i];
		} else if (A[i]>0) {
			if (tmp_max_product!=0) {
				tmp_max_product = tmp_max_product*A[i];
			} else {
				tmp_max_product = A[i];
			}
			tmp_min_product = min (tmp_min_product * A[i], 1);
		} else {
			int tmp = tmp_max_product;
			tmp_max_product = max(tmp_max_product * A[i] , 1);
			tmp_min_product = tmp * A[i];
		}
		
		if (max_product < tmp_max_product) {
			max_product = tmp_max_product;
		}
		
	}

	return max_product;
}

int main() {

int A[] = {0,0,0,0,1};

printf(" %d ",max_subarray_product(A,5));


return 0;
}
