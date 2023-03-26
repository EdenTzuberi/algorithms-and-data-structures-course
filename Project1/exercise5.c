#include <stdio.h>

float Nth_term_in_seq(a, b, c, index)
{
	float num = 0, denominator = 0, numerator = 0, array[3] = { a, b, c};

	if (index == 1 || index == 2 || index == 3)
	{
		return array[index - 1];
	}

	numerator = index * Nth_term_in_seq(a, b, c, index-1);
	denominator = (index - 2) * Nth_term_in_seq(a, b, c, index - 3);

	return num = numerator / denominator;

}

void main()
{
	int a, b, c, index;

	printf("insert the first num of a seq: \n");
    scanf_s("%d", &a);
	printf("insert the second num of a seq: \n");
	scanf_s("%d", &b);
	printf("insert the third num of a seq: \n");
	scanf_s("%d", &c);
	printf("insert the Nth index of the seq to print it's value: \n");
	scanf_s("%d", &index);
	printf("The value of index %d is %0.3f\n", index, Nth_term_in_seq(a, b, c, index));
}