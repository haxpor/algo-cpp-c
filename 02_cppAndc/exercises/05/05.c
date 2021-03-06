#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

// define declaration of struct and its typedef
// to let definition of struct later knows a short named of typedef we just did here
struct LinkedListItem;
typedef struct LinkedListItem LinkedListItem;

// define its definition of struct
struct LinkedListItem
{
	char value;
	LinkedListItem* next;
	LinkedListItem* prev;
};

// convert input decimal to binary representation
// note: this is not so efficient, I didn't take more time to optimize and refactor this.
// just take this function as learning point for dynamically allocate struct, and doubly-linked-list
void binaryNotEfficient(int x)
{
	int h, r;
	int xCopy = x;
	LinkedListItem* bitem = NULL;
	LinkedListItem* currItem = NULL;
	int resultCharCount = 0;

	do
	{
		h = (int)floor(xCopy / 2);
		r = xCopy % 2;
		if (h == 0)
		{
			// now we work on the next item
			LinkedListItem *nextItem = malloc(sizeof(LinkedListItem));
			nextItem->value = r +'0';

			// link to previous item
			nextItem->prev = currItem;
			// set null to next item
			nextItem->next = NULL;

			// link previous to new item
			currItem->next = nextItem;

			// move current item pointer to this item
			currItem = nextItem;

			resultCharCount++;
			break;
		}
		else
		{
			// continue
			if (bitem == NULL)
			{
				bitem = malloc(sizeof(LinkedListItem));
				bitem->value = r + '0';

				bitem->next = NULL;
				bitem->prev = NULL;

				// set current pointer for item
				currItem = bitem;
				
				xCopy = h;
				
				resultCharCount++;
			}
			else
			{
				// now we work on the next item
				LinkedListItem *nextItem = malloc(sizeof(LinkedListItem));
				nextItem->value = r +'0';

				// link to previous item
				nextItem->prev = currItem;
				// set null to next item
				nextItem->next = NULL;

				// link previous to new item
				currItem->next = nextItem;

				// move current item pointer to this item
				currItem = nextItem;

				xCopy = h;

				resultCharCount++;
			}
		}
	} while(1);

	// define enough lengh of string to hold result
	char resultBinaryString[resultCharCount + 1];
	memset(resultBinaryString, '\0', sizeof(resultBinaryString));
	int i = 0;
	
	// reverse print result from buffer linkedlist
	// currItem points to the last item in the list
	while (currItem != NULL)
	{
		// collect result
		resultBinaryString[i++] = currItem->value;

		// traverse backward
		currItem = currItem->prev;
	}

	printf("%s\n", resultBinaryString);

	// free all dynamically allocated struct
	currItem = bitem;
	while (currItem != NULL)
	{
		LinkedListItem* next = currItem->next;
		free(currItem);

		currItem = next;
	}
}

// more efficient function to convert input decimal to binary then print it
// use pre-allocated enough size of array as backend data structure to hold binary representation
void binary(int x)
{
	// allocate number of characters equal to number of bits that could represent maximum number in int
	// this is reverse of result binary string
	char resultRevBinaryString[sizeof(int) * 8];

	int h, r;
	int strCount = 0;

	do
	{
		h = (int)floor(x / 2);
		r = x % 2;
		if (h == 0)
		{
			// we're done
			resultRevBinaryString[strCount++] = r + '0';
			break;
		}
		else
		{
			resultRevBinaryString[strCount++] = r + '0';
			x = h;
		}
	} while (1);

	// print result in reverse
	while (strCount >= 0)
	{
		printf("%c", resultRevBinaryString[strCount--]);
	}

	printf("\n");
}

int main(int argc, char* args[])
{
	binaryNotEfficient(450);
	binary(450);
	return 0;
}
