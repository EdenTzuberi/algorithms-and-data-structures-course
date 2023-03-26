#include <stdio.h>
#include <stdlib.h>

#include "stack.h"
#include "def.h"
#include "exe.h"
#include "list.h"
#include "queue.h"

void main()
{
	int length, length_of_queue, value, arr[] = {1, 2, 4, 7, 8}, max = 0;
	STACK *t_stack;
	QUEUE t_queue;


	//S_init(&t_stack);
	//length = sizeof(arr)/sizeof(*arr);
	//AddArrayValueToStack(&t_stack, arr, length);
	//S_print(&t_stack);
	//max = findMaxInStack(&t_stack);
	//printf("max value in stack is %d\n", max);
	//S_print(&t_stack);
	//printf("\n");
	//printf("top value in stack is %d\n", S_top(&t_stack));
	//printf("\n");
	//Sort_Stack(&t_stack);
	//printf("the sorted stack is:\n");
	//S_print(&t_stack);
	//printf("\n");


	//InitQueueFromArr(&t_queue, arr, length);
	//printf("\n");
	//Q_print(&t_queue);
	//printf("\n");
	//printf("\nTHE HEAD BEFORE CHECK IS %d\n", Q_head(&t_queue));
	//value = checkDivQueue(&t_queue);
	//printf("\nthe queue is %d (TRUE/FALSE)\n", checkDivQueue(&t_queue));
	//Q_print(&t_queue);
	//printf("\nTHE HEAD IS %d\n", Q_head(&t_queue));

	S_init(&t_stack);
	length = sizeof(arr)/sizeof(*arr);
	AddArrayValueToStack(&t_stack, arr, length);
	S_print(&t_stack);
	printf("the stack is %d (1-for sorted, 0 for unsorted)\n", is_sorted(t_stack));

}