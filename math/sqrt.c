#include<stdio.h>
double absolute_diff(double a, double b)
{
	double df = a-b;
	if (df<0) { return -1*df;}
	else return df;
}
double squrt(double val)
{
	double start = 0;
	double prevMid=0;
	double end = val;
	double mid = (start+end)/2.0;
	while (absolute_diff(mid,prevMid)>0.00000001){
		prevMid = mid;
		if (mid*mid>val) {
			end = mid;
		} else {
			start = mid;
		}
		mid = (start+end)/2.0;
	}

	return mid;
}

int main()
{
	printf(" === SQRT =====\n");
	printf(" %lf ", squrt(5.000000000));
	printf(" \n--- SQRT -----\n");
return 0;
}