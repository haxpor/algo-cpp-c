/*
 * The program has getError() to get latest pervious error in which setErrorString() can be set when convert() found any error.
 * So main() could detect any error detect along with returned value returned from it.
 *
 * The program pre-allocate memory around 255*2 + 32 + 11 = 553 bytes at least to accomodate error reporting, and string input each time (generously allocate more).
 * 
 * Last, use fgets() to accept input from user including space (not scanf, and not gets. The latter is dangerous as it doesn't know before hand how many bytes to operate).
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ERROR -1
#define MAX_POSSIBLE_INPUT_BUFF 32
#define MAX_CONVERTED_NUM_LENGTH 11
#define MAX_ERROR_STR_BUFF 255

char errorString[MAX_ERROR_STR_BUFF];
char errorStringFront[MAX_ERROR_STR_BUFF];

void setErrorString(const char* str)
{
	// set error string to holder error string
	strncpy(errorString, str, strlen(str));
}

char* getError()
{
	// copy string from holder to front buffer
	strncpy(errorStringFront, errorString, strlen(errorString));

	// empty holder string
	// now next time we won't report error as we don't want to
	memset(errorString, '\0', sizeof(errorString));

	// return front buffer
	return errorStringFront;
}

// read one decimal number one character at a time, end with space
// then return result decimal value
// if there's any error happen due to malformed input then return -1 with 
int convert()
{
	char tmpBuff[MAX_POSSIBLE_INPUT_BUFF];	// holder of fgets()
	char inputBuff[MAX_CONVERTED_NUM_LENGTH]; // for length of int which has 4 bytes included one character for null terminated character
	memset(inputBuff, '\0', sizeof(inputBuff));

	int i = 0;	// index used for inputBuff

	do
	{
		printf("enter: ");
		fgets(tmpBuff, sizeof(tmpBuff), stdin);
		
		// only accept a single decimal number one at a time so don't care for '+' and '-' to be enter.
		if ((tmpBuff[0] >= '0' && tmpBuff[0] <= '9'))
		{
			inputBuff[i++] = tmpBuff[0];
			printf("inputBuff: %s\n", inputBuff);
		}	
		else if (tmpBuff[0] == ' ')
		{
			printf("compute");
			return atoi(inputBuff);
		}
		else
		{
			// as well instead we could just print the error out immediately, then continue to next loop
			setErrorString("Malformed input character");
			return ERROR;
		}
	} while(1);
}

int main(int argc, char* args[])
{
	int value = convert();
	char* errorStr = getError();
	if (value == ERROR && strlen(errorStr) > 0)
	{
		printf("Error: %s\n", errorStr);
		return -1;
	}
	else
	{
		printf("value = %d\n", value);
		return 0;
	}
}
