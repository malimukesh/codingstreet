/* Counting Sort Code by codingstreet.com
Complexity: O(n+k);
n is number of object in the array
k is range of input
*/
#include<stdio.h>
#include<stdlib.h>
 
void printarray(int A[],int size){
    int i;
    printf("\n ");
    for(i=0;i<size;i++)
        printf("%d ",A[i]);
}
 
void counting_sort(int A[],int size)
{
	int min,max,i,range,*p,j;
	min=A[0],max=A[0];
    
    for(i=0;i<size;i++){
            if(A[i]<min) min=A[i];
            if(A[i]>max) max=A[i];
    }

	range=max-min+1;
	p=malloc(sizeof(int)*range);
    
    for(i=0;i<range;i++) p[i]=0;
 
    for(i=0;i<size;i++)
    {
        p[A[i]-min]+=1;
    }
    
    int k=0;

    for(i=0;i<range;i++)
    {
		j=p[i];    	
		while(p[i]!=0 && j!=0)
		{
			A[k]=i+min;
			k++;
			j--;      
		}
    }
}

int main(){
 
int A[]={5,9,8,6,15,11,7,5,8};
 
int n=sizeof(A)/sizeof(A[0]);
// Array Before Sorting
printf("\n Input Array : ");
printarray(A,n);
counting_sort(A,n);
// Array After counting Sort
printf("\n Output Array : ");
printarray(A,n);
printf("\n");
return 0;
}