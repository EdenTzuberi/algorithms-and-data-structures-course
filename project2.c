#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef int DATA; //list int type
typedef enum { False, True } BOOL;	// a boolean type

typedef struct node {

	DATA         key;
	struct node* next;

}NODE;

typedef struct {

	NODE head;

}LIST;

//LIST myList;

typedef struct d_node
{
	
	DATA         key;
	struct d_node* next;
	struct d_node* prev; //for doubly linked list

}D_NODE;

typedef struct {

	D_NODE head;

}DLIST;


BOOL L_init(LIST* pList)
{
	if (pList == NULL)
		return False;	// no list to initialize

	pList->head.next = NULL;
	return True;
}

BOOL DL_init(DLIST* pList)
{
	if (pList == NULL)
		return False;	// no list to initialize

	pList->head.next = NULL;
	return True;
}

NODE* L_insert(NODE* pNode, DATA Value)
{
	NODE* tmp;

	if (!pNode)
		return NULL;

	tmp = (NODE*)malloc(sizeof(NODE));	// new node

	if (tmp != NULL) {
		tmp->key = Value;
		tmp->next = pNode->next;
		pNode->next = tmp;
	}
	return tmp;
}

D_NODE* DL_insert(D_NODE* pNode, DATA Value)
{
	D_NODE* tmp;

	if (!pNode)
		return NULL;

	tmp = (D_NODE*)malloc(sizeof(D_NODE));	// new node

	if (tmp != NULL) {
		tmp->key = Value;
		tmp->next = pNode->next;
		pNode->next = tmp;
	}
	return tmp;
}

void CreateListFromArr(LIST* pList, int* arr, int size)
{
	NODE* nodes;
	int i;
	// Initialization
	L_init(pList);
	nodes = &(pList->head);
	for (i = 0; i < size; i++)
	{
		nodes = L_insert(nodes, arr[i]);
	}
}

void Create_DListFromArr(DLIST* pList, int* arr, int size)
{
	D_NODE* nodes;
	int i;
	// Initialization
	DL_init(pList);
	nodes = &(pList->head);
	for (i = 0; i < size; i++)
	{
		nodes = DL_insert(nodes, arr[i]);
	}
}

int CountSeq(LIST* pList, int num)
{
	int counter = 0;
	NODE* pN = pList->head.next;
	while (pN != NULL)
	{
		if (pN->key == num)
		{
			counter++;
			while (pN->key == num && pN->next != NULL)
			{
				pN = pN->next;
			}

		}

		pN = pN->next;
	
	}
	
	free(pN);

	return counter;
}

void InsertSeq(DLIST* list1, DLIST* list2)
{
	int counter1, counter2, mid, i = 0;
	D_NODE* pN2 = list2->head.next, *pN1_start = list1->head.next, * pN1_end;
	if (!list1 || !list2) return NULL;
	counter1 = countNODES(list1);
	counter2 = countNODES(list2);
	mid = counter1 / 2;

	for (i = 0; i < mid - 1; i++)
	{
		pN1_start = pN1_start->next;
	}

	pN1_end = pN1_start->next;

	if (list2 != NULL)
	{

		pN1_start->next = pN2;

		while (pN2->next != NULL)
		{
			pN2 = pN2->next;
		}

		if (pN2->next == NULL)
		{
			pN2->next = pN1_end;
		}

	}
}

/*void InsertSeq(LIST* list1, LIST* list2)
{
	int counter1, counter2, mid, i = 0;
	NODE* pN1_start = list1->head.next, *pN1_end, *pN2 = list2->head.next;
	if (!list1 || !list2) return NULL;
	counter1 = countNODES(list1);
	counter2 = countNODES(list2);
	mid = counter1 / 2;

	for (i = 0; i < mid-1 ; i++)
	{
		pN1_start = pN1_start->next;
	}

	pN1_end = pN1_start->next;

	if (list2 != NULL)
	{
		
		pN1_start->next = pN2;

		while (pN2->next != NULL)
		{
			pN2 = pN2->next;
		}

		if (pN2->next == NULL)
		{
			pN2->next = pN1_end;
		}
		
	}
}*/

int count_DNODES(DLIST *pList) //change all to dnodes
{
	int counter = 0;
	D_NODE* pN = pList->head.next;
	while (pN != NULL)
	{
		counter++;
		pN = pN->next;
	}
	free(pN);
	return counter;
}

int countNODES(LIST *pList)
{
	int counter = 0;
	NODE* pN = pList->head.next;
	while (pN != NULL)
	{
		counter++;
		pN = pN->next;
	}
	free(pN);
	return counter;
}

int L_print(LIST* pList)
{
	NODE* tmp;
	int		c = 0;

	if (!pList)
		return False;

	printf("\n");
	tmp = pList->head.next;
	while (tmp != NULL)
	{
		printf(" %d ---> ", tmp->key);
		c++;
		tmp = tmp->next;
	}
	printf("\n");
	return c;
}

int DLIST_print(DLIST* pList)
{
	D_NODE* tmp;
	int		c = 0;

	if (!pList)
		return False;

	printf("\n");
	tmp = pList->head.next;
	while (tmp != NULL)
	{
		printf(" %d ---> ", tmp->key);
		c++;
		tmp = tmp->next;
	}
	printf("\n");
	return c;
}

BOOL Check_if_list1_max(LIST *list1, LIST *list2)
{
	NODE* pN1 = list1->head.next, * pN2 = list2->head.next;
	int num1 = 0, num2 = 0, counter1, counter2, i;
	counter1 = countNODES(&list1);
	counter2 = countNODES(&list1);
	for ( i = 0; i < counter1 - 1; i++)
	{
		num1 = pN1->key * pow(10, i);
		pN1 = pN1->next;
	}
	for (i = 0; i < counter2 - 1; i++)
	{
		num2 = pN2->key * pow(10, i);
		pN2 = pN2->next;
	}
	if (num1 > num2)
	{
		return 1;
	}
	else
	{
		return 0;
	}

}

void main()
{

		
		
	//exercise 4
//////////////////////////////////////

	 
			int num, counter;
			LIST	list1, list2;
			DLIST Dlist1, Dlist2;

			
			int arr[] = { 4, 22, 3, 4, 5, 6, 6, 3, 4, 4, 4 };
			int size = sizeof(arr) / sizeof(int);
			CreateListFromArr(&list1, arr, size);
			L_print(&list1);
			printf("insert number to count how many times it's sequences exist in the list \n");
			scanf_s("%d", &num);
			counter = CountSeq(&list1, num);
			printf("the num %d appears %d in the list\n", num, counter);

////////////////////////////////////////////
			int arr1[] = { 3, 6, 4, 88 };
			int size1 = sizeof(arr1) / sizeof(int);
			int arr2[] = { 10, 40, 30 };
			int size2 = sizeof(arr2) / sizeof(int);
			Create_DListFromArr(&Dlist1, arr1, size1);
			Create_DListFromArr(&Dlist2, arr2, size2);
			DLIST_print(&Dlist1);
			DLIST_print(&Dlist2);
			InsertSeq(&Dlist1, &Dlist2);
			DLIST_print(&Dlist1);

/////////////////////////////////////////////////

			int arr1[] = { 6, 2, 5 };
			int size1 = sizeof(arr1) / sizeof(int);
			int arr2[] = { 0, 0, 6 };
			int size2 = sizeof(arr2) / sizeof(int);
			CreateListFromArr(&list1, arr1, size1);
			CreateListFromArr(&list2, arr2, size2);
			printf("%d", Check_if_list1_max(&list1, &list2));







}