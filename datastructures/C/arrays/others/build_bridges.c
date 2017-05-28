#include<stdio.h>
#include<stdlib.h>
struct pair {
	int north;
	int south;
};

void sourt_pair_by_south(struct pair *A, int n)
{
	int i,j;
	for (i=0;i<n;i++)
	{
		for (j=0; j<n; j++) 
		{
			if (A[j].south<A[i].south)
			{
				int temp1 = A[i].north;
				int temp2 = A[i].south;
				
				A[i].north = A[j].north;
				A[i].south = A[j].south;
				A[j].north = temp1;
				A[j].south = temp2;
			}
		}
	}
}

void print_pairs(struct pair pairs[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("(%d,%d)\n",pairs[i].north,pairs[i].south);
	}
}

int no_of_longest_increasing_sub_array(struct pair pairs[], int n)
{
	int i,j,max;
	int *LIS;
	LIS = (int *) malloc(sizeof(int)*n);
	for (i=0;i<n;i++) LIS[i]=1;
	for (i=0;i<n;i++)
	{
		for (j=0; j<i; j++)
		{
			if (pairs[i].north>pairs[j].north && LIS[i]<(LIS[j]+1))
			{
				LIS[i] = LIS[j] + 1;
			}
		}
	}

	max = LIS[0];

	for (i=0; i<n; i++) {
		if(max < LIS[i]) { 
			max = LIS[i];
		} 
	}

	return max;

}

int main()
{

struct pair pairs[4];

int i;
int n = 4;
for(i=0;i<n;i++) 
{
	scanf("%d %d",&pairs[i].north, &pairs[i].south);
}
printf("\n===========INPUT PAIRS===============\n");
sourt_pair_by_south(pairs,n);
print_pairs(pairs, n);
printf ("\n[ %d ]\n",no_of_longest_increasing_sub_array(pairs, n));


return 0;
}
