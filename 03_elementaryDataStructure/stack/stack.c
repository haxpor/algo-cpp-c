#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

void stack_init(struct Stack *stack, int max)
{
#ifndef STACK_OPTIMIZED
	if (stack == NULL)
		return;
#endif

	stack->max = max;
	stack->i = 0;
	stack->p = malloc(sizeof(STACK_TYPE) * max);
}

void stack_destroy(struct Stack *stack)
{
#ifndef STACK_OPTIMIZED
	if (stack == NULL)
		return;
#endif

	free(stack->p);
	stack->p = NULL;
	stack->i = 0;
}

void stack_push(struct Stack *stack, STACK_TYPE item)
{
#ifndef STACK_OPTIMIZED
	if (stack == NULL)
		return;	
#endif

	if (!stack_full(stack))
	{
		// use the following line or next line
		// just leave here for reference that we could do both
		// p[] will automatically dereference value from pointer for us
		//
		//(stack->p[stack->i]) = item;
		*(stack->p + stack->i) = item;
		(stack->i)++;
	}
}

STACK_TYPE *stack_pop(struct Stack *stack)
{
#ifndef STACK_OPTIMIZED
	if (stack == NULL)
		return NULL;	
#endif

	if (!stack_empty(stack))
		return (stack + --(stack->i))->p;
	else
		return NULL;
}

bool stack_empty(struct Stack *stack)
{
#ifndef STACK_OPTIMIZED
	if (stack == NULL)
		return false;	
#endif

	if (stack->i == 0)
		return true;
	else
		return false;
}

bool stack_full(struct Stack *stack)
{
#ifndef STACK_OPTIMIZED
	if (stack == NULL)
		return false;	
#endif

	if (stack->i >= stack->max)
		return true;
	else
		return false;
}
