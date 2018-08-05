/**
 * gcd-modulush
 *
 * gcd accepts input parameter of x, and y via command line argument.
 */

#include <stdio.h>
#include <stdlib.h>
#include "gcd.h"

int main(int argc, char** argv) {
	if (argc < 2) {
		fprintf(stderr, "Missing required input parameters of x, and y\n");
		exit(1);
	}
	else if (argc < 3) {
		fprintf(stderr, "Missing y parameter\n");
		exit(1);
	}

	// get x
	int x = atoi(argv[1]);
	if (x <= 0) {
		fprintf(stderr, "x cannot be zero or negative\n");
		exit(1);
	}
	// get y
	int y = atoi(argv[2]);
	if (y <= 0) {
		fprintf(stderr, "y cannot be zero or negative\n");
		exit(1);
	}

	printf("gcd(%d,%d) = %d\n", x, y, gcd(x,y));
}
