#include <stdio.h>
#include <math.h>

int foo(const int a[], int n)
{
	int reversed_num = 0;
	if (n == 0)
	{
		return 0;
	}
	reversed_num = a[n - 1] * pow(10, n - 1);
	n--;
	return reversed_num + foo(a,n);
}


void main()
{
	int length, a[] = {0, 2, 3, 0, 9, 0, 0};
	length = sizeof(a)/sizeof(int);
	printf("the reversed num is %d", foo(a, length));
}