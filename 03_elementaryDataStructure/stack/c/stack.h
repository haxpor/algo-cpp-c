/*
 * Stack implementation
 *
 * It uses the following #define to ditates the way its behave
 * - STACK_TYPE
 *	 Set to primitive type. If not define, it will default to int.
 *
 * - STACK_OPTIMIZE
 *   Define or set to any value to ignore NULL checking of input stack parameter of all functions.
 */

#ifndef stack_h_
#define stack_h_

#include <stdbool.h>

/*
 * If not define STACK_TYPE elsewhere then
 * define it as int
 */
#ifndef STACK_TYPE
#define STACK_TYPE int
#define STACK_TYPE_FP 0
#endif

struct Stack
{
	/*
	 * Data hold by stack,
	 * its type is defined by STACK_TYPE
	 */
	STACK_TYPE *p;

	/*
	 * Maximum number of elements hold
	 * by stack.
	 */
	int max;

	/* used internally */
	int i;
};

/*
 * Initialize a stack.
 * This allows user to create a Stack prior to this call either on stack, or heap.
 * It doesn't assume to be in either one of both.
 *
 * Thus caller still has responsibility to free their own Stack variable in declaration.
 */
extern void stack_init(struct Stack *stack, int max);

/*
 * Destroy stack's data.
 *
 * Caller still has responsibility to free Stack itself structure.
 * This will only destroy its internal data, along with resetting its stack's internal variables.
 *
 */
extern void stack_destroy(struct Stack *stack);

/*
 * Push a new item into stack.
 */
extern void stack_push(struct Stack *stack, STACK_TYPE item);

/*
 * Pop an item from stack.
 * It return pointer to STACK_TYPE for returned item, otherwise return NULL.
 */
extern STACK_TYPE *stack_pop(struct Stack *stack);

/*
 * Return whether stack is empty.
 *
 * Return false if stack empty, or true if not.
 * As well return false if input stack is NULL in which only if STACK_OPTIMIZED is not defined.
 */
extern bool stack_empty(struct Stack *stack);

/*
 * Return whether stack is full.
 *
 * Return false if stack is not full, or true if full,
 * As well return false if input stack is NULL in which only if STACK_OPTIMIZED is not defined.
 */
extern bool stack_full(struct Stack *stack);

#endif /* stack_h_ */
