#include <stdio.h>

double S(float n)
{
	if (n == 0)
		return 0;
	return (1 / (1 + 4*(n-1)) + S(n - 1)); //[1/(an= a1+(n-1)d)] arithmetic sequence formula. 
}

void main()
{
	float n;
	printf("Insert number to calculate arithmetic sequence series\n");
	scanf_s("%f", &n);
	printf("The sum is = %0.4f", S(n));
}

