/*
 * Two versions of gcd implementation using subtract, and modulo operation then measure how many times each one
 * took for executions.
 *
 * Clearly gcd() took 8 times while gcdNotEfficient() took 260 times.
 */

#include <stdio.h>

int gcdNotEfficient(int u, int v) {
	int t, count=0;
	
	while (u > 0) {
		if (u < v) {
			t = u;
			u = v;
			v = t;
		}
		u = u - v;
		count++;
	}
	printf(" - gcdNotEfficient executed %d times\n", count);
	return v;
}

int gcd(int u, int v) {
	int t, count=0;
	
	while (u > 0) {
		if (u < v) {
			t = u;
			u = v;
			v = t;
		}
		u = u % v;
		count++;
	}
	printf(" - gcd executed %d times\n", count);
	return v;
}

int main(int argc, char* args[])
{
	printf("gcd(12345, 56789) = %d\n", gcdNotEfficient(12345, 56789));
	printf("gcd(12345, 56789) = %d\n", gcd(12345, 56789));

	return 0;
}
