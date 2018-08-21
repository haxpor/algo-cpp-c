/*
 * See more info about Sieve of Eratosthenes at https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
 */

#include <stdio.h>
#include <stdbool.h>
#include <time.h>

#define N 1000

// change this to false to disable measuring execution time of sieve() function
#define MEASURE_EXEC_TIME true

// return result of prime number up to specified input size
// refer to answer for more detail about "array decays to pointers" as seen https://stackoverflow.com/questions/10186765/what-is-the-difference-between-char-array-vs-char-pointer-in-c
// we use pointer as parameter of function be the same as what actually happens behind the scene
// note you need to pass as &array[0] into the function
void sieve(bool* resultArray, int size)
{
#if (MEASURE_EXEC_TIME == true)
	// start to measure time
	clock_t t = clock();
#endif

	int i, j;
	
	// result for both number 0 and 1 are not prime
	// so we set it first
	resultArray[0] = 0;
	resultArray[1] = 0;

	// ignore index 0, and 1 as we don't have interest in terms of prime number
	for (resultArray[1] = 0, i = 2; i <= size; i++)
	{
		resultArray[i] = 1;
	}

	// multiple of number of any other number cannot be prime
	// this loop section set it as non-prime
	for (i = 2; i <= N/2; i++)
	{
		for (j = 2; j <= N/i; j++)
		{
			resultArray[i*j] = 0;
		}
	}

#if (MEASURE_EXEC_TIME == true)
	// end of measure time
	t = clock() - t;
	double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
	printf("sieve() took %f seconds to execute\n", time_taken);
#endif
}

// print result from input sieve array
void printSieveResult(bool* array, int size)
{
	// print result
	for (int i = 0; i <= N; i++)
	{
		if (array[i])
		{
			printf("%d ", i);
		}
	}
	printf("\n");
}

int main(int argc, char* args[])
{
	bool primes[N+1];
	sieve(&primes[0], N+1);
	printSieveResult(&primes[0], N+1);
	
	return 0;
}
