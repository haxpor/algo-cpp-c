#include <stdio.h>
#include "stack.h"
#include <assert.h>

#define PA(x) printAllItems(&x)
#define PUSH(s, v) stack_push(&s, v)
#define POP(s) stack_pop(&s)

void printAllItems(struct Stack *stack)
{
	for (int i=0; i<stack->i; i++)
	{
#if STACK_TYPE_FP == 1
		// STACK_TYPE_FP is an additional macro variable to indicate that
		// stack's type is in floating point, so we could adapt data type
		// to print here
		printf("%lf ", *(stack->p + i));
#else
		printf("%d ", *(stack->p +i));
#endif
	}
	printf("\n");
}

int main()
{
	// print size of data type used in stack via STACK_TYPE
	printf("size of STACK_TYPE is %lu\n", sizeof(STACK_TYPE));

	struct Stack myStack;
	stack_init(&myStack, 20);
	PUSH(myStack, 1); PA(myStack);
	PUSH(myStack, 2); PA(myStack);
	PUSH(myStack, 3); PA(myStack);
	PUSH(myStack, 4); PA(myStack);
	POP(myStack); PA(myStack);
	POP(myStack); PA(myStack);
	PUSH(myStack, 6); PA(myStack);
	stack_destroy(&myStack);

	assert(myStack.p == NULL);

	return 0;
}
