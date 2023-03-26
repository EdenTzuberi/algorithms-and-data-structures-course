//exercise 2
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "BSTree.h"


int HightOfTree(NODE2* v)
{
	int L_hight, R_hight;
	if (!v)
	{
		return 0;
	}

	L_hight = HightOfTree(v->left);
	R_hight = HightOfTree(v->right);

	return 1 + max(L_hight, R_hight);
}

int CheckBalancedTree(NODE2* v)
{
	int Left, Right;

	if (!v)
	{
		return 1;
	}

	Left = HightOfTree(v->left);
	Right = HightOfTree(v->right);
	if (abs(Left - Right) > 1)
	{
		return 0;
	}
	else 
	{
	    return CheckBalancedTree(v->left) && CheckBalancedTree(v->right);
		
	}
}


