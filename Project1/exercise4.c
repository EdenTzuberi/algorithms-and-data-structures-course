#include <stdio.h>

int Arrangement_Options(balls, cells)
{
	int options = 0, power;

	power = balls / 3;

	if (balls % 3 !=0 || cells < (balls / 3) || cells == 0)
	{
		return 0;
	}

	if(balls / 3 == cells || balls == 3 && cells == 1 || balls == 0 && cells > 0 )
	{
		return 1;
	}

	return Arrangement_Options(balls - 3, cells - 1) + Arrangement_Options(balls, cells - 1);
}

void main()
{
	int balls, cells;
	printf("Enter number of balls.\n");
	scanf_s("%d", &balls);
	printf("Enter number of cells.\n");
	scanf_s("%d", &cells);
	printf("There are %d arrangement options.\n", Arrangement_Options(balls, cells));
}