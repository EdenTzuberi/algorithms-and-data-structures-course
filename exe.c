#include <stdio.h>
#include <stdlib.h>
#include "exe.h"
#include "stack.h"
#include "def.h"
#include "list.h"
#include "queue.h"


//exericse 2
void S_SpillOn(STACK *pFromStk, STACK *pToStk)
{
	while (!S_isEmpty(pFromStk))
	{
		S_push(pToStk, S_pop(pFromStk));
	}
}

int findMaxInStack(STACK* pStack)
{
	int temp, max_term = 0;
	STACK s_temp;
	S_init(&s_temp);

	if (pStack == NULL)
		return;
	

	while (!S_isEmpty(pStack))
	{
		temp = S_pop(pStack);

		if (temp > max_term)
		{
			max_term = temp;
			S_push(&s_temp, temp);
		}
		else
		{
			S_push(&s_temp, temp);
		}

	}

	while (!S_isEmpty(&s_temp))
	{
		if (S_top(&s_temp) == max_term)
		{
			S_pop(&s_temp);
		}
		
		S_push(pStack, S_pop(&s_temp));
	}
	
	return max_term;
}

//exercise3
//the complexity of the function is o(n^2)
void Sort_Stack(STACK* pStack)
{
	int temp, max;
	STACK s_temp;
	S_init(&s_temp);

	max = findMaxInStack(pStack);
	S_push(&s_temp, max);
	
	while (!S_isEmpty(pStack))
	{
		
		if (S_top(pStack) == max)
		{
			S_pop(pStack);
		}
		
		if (S_top(pStack) < S_top(&s_temp))
		{
			S_push(&s_temp, S_pop(pStack));
		}
		
		else
		{
			temp = S_pop(pStack);
			while (temp > S_top(&s_temp)) 
			{
				S_push(pStack, S_pop(&s_temp));
			}
			S_push(&s_temp, temp); 
		}
	}

	S_SpillOn(&s_temp, pStack);
}


//exercise 5
//the complexity of the function is o(n)
int checkDivQueue(QUEUE* pQue)
{
	int flag, value = 0, temp = 0;
	if (Q_isEmpty == NULL)
	{
		return 0;
	}

	flag = -1;
	Q_enque(pQue, flag); 

	while (Q_head(pQue) != flag && temp != flag)
	{
		temp = Q_deque(pQue);
		Q_enque(pQue, temp);

		if ((temp % Q_head(pQue)) != 0)
		{
			while (Q_head(pQue) != flag)
			{
				Q_enque(pQue, Q_deque(pQue));
			}

			if (temp == flag || Q_head(pQue) == flag)
			{
				Q_deque(pQue);
				return 0;
			}
		}

		else
		{
			while (temp % Q_head(pQue) == 0)
			{
				temp = temp / Q_head(pQue);
				Q_enque(pQue, Q_deque(pQue));

				if (temp == flag || Q_head(pQue) == flag)
				{
					Q_deque(pQue);
					return 1;
				}

				if (temp == 1)
				{
					value = 1;
					temp = Q_head(pQue);
					Q_enque(pQue, Q_deque(pQue));
				}
				
				else
				{
					if ((Q_head(pQue) != flag) && (temp % Q_head(pQue) != 0) && (temp != flag))
					{
						return 0;
					}
				}	
			}
		}
	}

	return value;
}

//from tests 
int is_sorted(STACK* pstack)
{
	int temp;
	if (S_isEmpty(pstack))
	{
		return 1;
	}
	
	temp = S_pop(pstack);
	
	if (temp > S_top(pstack))
	{
		return 0;
	}

	return is_sorted(pstack);


}




