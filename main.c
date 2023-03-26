#include <stdio.h>
#include <stdlib.h>
#include "BSTree.h"
#include "def.h"
#include "exe.h"



void main()
{
	int num;
	TREE T;

	T_init(&T);
	
	NODE2 *v = T.head.left;

	
	//T_insert(&T, 5);
	//T_insert(&T, 8);
	//T_insert(&T, 6);
	//T_insert(&T, 7);
	//T_insert(&T, 9);

	//T_insert(&T, 4);
	//T_insert(&T, 5);
	//T_insert(&T, 3);
	//T_insert(&T, 2);
	//T_insert(&T, 1);

	//T_insert(&T, 5);
	//T_insert(&T, 4);
	//T_insert(&T, 6);

	T_insert(&T, 8);
	T_insert(&T, 7);
	T_insert(&T, 6);
	T_insert(&T, 5);
	T_insert(&T, 9);
	T_insert(&T, 10);
	T_insert(&T, 11);

	PrintTree(T.head.left);
	printf("\n");
	printf("The tree is balanced tree? (true/false) %d\n", CheckBalancedTree(T.head.left));

	
}