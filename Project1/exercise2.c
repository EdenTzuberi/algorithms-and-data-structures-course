#include <stdio.h>

unsigned int digitCounter(unsigned int n, unsigned int digit)
{
	int counter = 0, quotient_num, reminder_num = 0; //reminder_num = the number after % operation. quotient_num = the number after divistion operation.
	if(n == 0)
	{
		return counter = 0;
	}

	reminder_num = n % 10;
	quotient_num = n / 10;

	if (reminder_num == digit)
	{
		counter++;
	}

	return counter = counter + digitCounter(quotient_num, digit);
}
		

void main()
{
	int n, digit;
	printf("Insert number\n");
	scanf_s("%d", &n);
	printf("Insert one digit to calculate the number of times it appears in the number\n");
	scanf_s("%d", &digit);
	printf("the digit appears %d in the number\n", digitCounter(n, digit));
}


