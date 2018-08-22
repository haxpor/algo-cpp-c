/*
 * Program accepts N, and M number at command line then print out sequence of number (person's order to be executed)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node;
typedef struct Node Node;

struct Node
{
	int key;
	Node* next;
};

/**
 * Wrapper function to strtol() function.
 * It tries to convert input string to long. If there's any error, error will be set with -1, and return value of -1.
 * Otherwise, no value set to error but returned converted value of input str.
 */
long wr_strtol(const char *str, int* error)
{
	char* endptr = NULL;
	int r = strtol(str, &endptr, 0);

	/* no conversion was performed */
	if (endptr == str)
	{
		if (error != NULL)
		{
			*error = -1;
		}
	}
	/* the entire string was converted, success */
	else if (*endptr == '\0')
	{
		return r;
	}
	/* the unconverted rest of the string starts at endstr */
	else
	{
		if (error != NULL)
		{
			*error = -1;
		}
	}

	// failed case
	return -1;
}

/*
 * Efficient version of josephus.
 */
void josephusEfficient(int n, int m, int* resultSeqArray)
{
	int i;
	Node *t, *x;

	t = malloc(sizeof(Node));
	t->key = 1;
	x = t;

	for (i=2; i <= n; i++)
	{
		t->next = malloc(sizeof(Node));
		t = t->next;
		t->key = i;
	}
	t->next = x;
	int j=0;

	while (t != t->next)
	{
		for (i=1; i<m; i++)
			t = t->next;

		x = t->next;
		*(resultSeqArray + j++) = x->key;
		t->next = x->next;
		free(x);
	}
	*(resultSeqArray + j) = t->key;

	free(t);
}

/*
 * Solve josephus problem.
 * Accepts n, and m then return out sequence of executed person as array.
 * Caller needs to ensure tha resultSeq has enough space to hold all result which is n.
 *
 * This version of implementation doesn't closely follow code in the book. Apparently it uses more local variables, and more checking statement.
 * Not quite optimized.
 */
void josephus(int n, int m, int* resultSeq)
{
	// form circular node
	Node* currNode = malloc(sizeof(Node));
	currNode->key = 1;
	Node* head = currNode;
	Node* targetNode = NULL;

	for (int i=1; i<n; i++)
	{
		Node* node = malloc(sizeof(Node));
		node->key = i+1;

		currNode->next = node;
		currNode = node;
	}
	currNode->next = head;
	currNode = head;

	// loop processing
	int count=1;
	int i=0;

	// if not itself then we keep looping
	while (currNode != NULL)
	{
		// at node before the target
		if (count >= m-1)
		{
			// current node
			targetNode = currNode->next;

			// save result
			// note: it's next node!
			*(resultSeq + i) = targetNode->key;

			if (currNode != targetNode)
			{
				// re-route node
				currNode->next = targetNode->next;

				// free target node
				free(targetNode);
				targetNode = NULL;

				// reset count
				// starting new at the next node so set it to 0
				count = 0;

				i++;
			}
			else 
			{
				break;
			}
		}

		// proceed to next node
		count++;
		currNode = currNode->next;
	}
}

void printAll(int *resultSeqArray, int size)
{
	if (resultSeqArray == NULL)
		return;

	for (int i=0; i<size; i++)
	{
		printf("%d ", *(resultSeqArray + i));
	}
	printf("\n");
}

/*
 * Accept parameter via command line as ./josephus <N> <M>
 */
int main(int argc, char* args[])
{
	if (argc < 3)
	{
		printf("Usage ./josephus <N> <M>\n");
		return -1;
	}

	int error = 0;

	// handle input n
	int n = (int)wr_strtol(args[1], &error);
	if (error == -1)
	{
		printf("error converting input N number\n");
		return -1;
	}
	
	// reset error handling
	error = 0;

	// handle input m
	int m = (int)wr_strtol(args[2], &error);
	if (error == -1)
	{
		printf("error converting input M number\n");
		return -1;
	}

	// allocate enough space to hold result
	int resultSeq[n];

	// josephus (self implementation)
	josephus(n, m, &resultSeq[0]);
	printf("josephus (not efficient)\n");
	printAll(&resultSeq[0], n);
	printf("\n");
	
	// zero out result array as we will reuse it
	memset(resultSeq, 0, sizeof(resultSeq));

	// josephus efficient implementation
	josephusEfficient(n, m, &resultSeq[0]);
	printf("josephus (efficient)\n");
	printAll(&resultSeq[0], n);

	return 0;
}
